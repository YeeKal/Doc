---
title: python 同步 notion 数据库
categories: blog
tags: tech
date: 2024-03-04
---

这个想法源自一个PostgreSQL数据库同步到notion的需求。在一个后端管理系统中，我想把远程PostgreSQL数据库里面的用户信息同步到notion里面，这样方便在notion里面对数据进行可视化，同时及时掌握数据库的变化趋势。

对于类似这样的同步需求，一般可以用一些自动化工具来完成，比如zapier(https://zapier.com/app/dashboard). 但是PostgreSQL的访问在zapier中是一个需要收费的高级功能。在搜索一通之后，虽然会出现很多类似这样同步的网站，但是大多都是不靠谱的方案。所以我决定自己写一个python脚本来完成这个需求。


```python
'''
EXAMPLE:  notion database operations with python
'''

# connect to notion database client
test_sync = DatabaseClient(...)

# insert one row
test_sync.insertRow(
    name="jack",
    age=10,
    text="hello",
    register_date=datetime.datetime.now().isoformat(),
    id=1
)

# update text property in a row with id as the main key
test_sync.updateByNumber(key='id', number=1, text="hi,boy")

```

## Notion api

Notion api 网址： https://developers.notion.com/

Notion api 是一个RESTful api，可以用来读写notion的数据库。在使用之前，需要先登陆 notion 账号，然后创建一个集成应用，获取一个token。这个token是用来访问notion api的凭证。

具体操作如下：

- 访问 notion 开发者网站，点击右上角`view my integrations`进行登陆并查看已有的集成应用

![notion integration](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304105928.png)

- 点击`new integration`创建一个新的集成应用，并起一个上口的名字。

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304110316.png)

- 记录下该应用的密钥，这个密钥是用来后面请求notion api的凭证。这里还可以编辑应用的图标，设置编辑权限等。

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304110459.png)

- 把该应用与notion的数据库进行关联。notion api里面创建的应用默认没有任何访问权限，需要手动添加权限。并且notion对应用权限做了很好的分区，可以只把部分页面授权给应用。点击需要授权页面右上角的`...`，滑动到下方的`connections`,点击`Connect to`,会跳出搜索界面，搜索刚刚创建的应用，点击并`confirm`即可完成授权。

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304111202.png)


不过noiotn原生的 RESTful api 非常繁琐，应该是为了保证文档各个属性的完整性，所以在使用api的时候需要通过多层嵌套的json传入数据。这样的话，对于一个有多种属性的数据库，需要写很多的json key-value字段。

举个例子：🌰

```bash
# for an example
# resource: https://developers.notion.com/reference/post-page
curl 'https://api.notion.com/v1/pages' \
  -H 'Authorization: Bearer '"$NOTION_API_KEY"'' \
  -H "Content-Type: application/json" \
  -H "Notion-Version: 2022-06-28" \
  --data '{
	"parent": { "database_id": "d9824bdc84454327be8b5b47500af6ce" },
  "icon": {
  	"emoji": "🥬"
  },
	"cover": {
		"external": {
			"url": "https://upload.wikimedia.org/wikipedia/commons/6/62/Tuscankale.jpg"
		}
	},
	"properties": {
		"Name": {
			"title": [
				{
					"text": {
						"content": "Tuscan Kale"
					}
				}
			]
		},
		"Description": {
			"rich_text": [
				{
					"text": {
						"content": "A dark green leafy vegetable"
					}
				}
			]
		},
...
```

notion_client是一个基于notion api的python库。这个库封装了RESTful请求的过程，可以直接通过设置properties来读写notion的页面。 但是由于properties里面属性太多了，这里面还是使用json结构来传入数据的。

立足于我当前的需求，我需要的只是对一个数据库的同步，同时数据库的字段类型不是很复杂，字段本身的样式，比如颜色，大小这些也不需要过渡设置。基于这些需求，利用上述的api，可以做一个极简的数据库同步的最小实现。


## python 实现

源代码链接：https://gist.github.com/YeeKal/59c85ec768857fe707d3fe4b587a49bd

核心实现只有100行左右，主要借助了notion_client的api，并对数据库操作进行了简易封装。

python操作noiton数据库的过程主要分为几个步骤：

- 创建数据库模板，主要指定notion数据库的数据类型，字段名。比如对于该数据库表格，可以用如下的模板来定义：

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304152143.png)

```python
template_cells = [
    Cell(type = PROPERTY_TYPE.TITLE, name='name', data=""),
    Cell(type = PROPERTY_TYPE.NUMBER, name='age', data=""),
    Cell(type = PROPERTY_TYPE.RICH_TEXT, name='text', data=""),
    Cell(type = PROPERTY_TYPE.DATE, name='register_date', data=""),
    Cell(type = PROPERTY_TYPE.NUMBER, name='id', data="")
]
```

其中`id`可以用来作为主键，作为一条数据的唯一标识，用来更新数据。

- 创建notion数据库客户端:

```python
# notion integration secret token
token = '<your token>'
#  database id
database_id = '<your database id>'

notion = Client(auth=token)
test_sync = DatabaseClient(database_id, notion,template_cells)
```

其中`token`就是我们上述创建的集成应用的密钥，`database_id`是我们需要同步的数据库的id。

- 插入数据

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304152920.png)

```python
# insert one row
test_sync.insertRow(
    name="jack",
    age=10,
    text="hello",
    register_date=datetime.datetime.now().isoformat(),
    id=1
)
# insert another row
test_sync.insertRow(
    name="lily",
    age=12,
    text="hi",
    register_date=datetime.datetime.now().isoformat(),
    id=2
    )
```


- 更新数据

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/0320240304153013.png)

```python
# update text property in a row with id=1
test_sync.updateByNumber(key='id', number=1, text="hi,boy")
```

这样的话，就可以使用比较简单的方式同步数据到notion数据库里面，并且不需要直接操作多层的json嵌套。

## 总结

这个脚本是一个最小实现，对于更加复杂的数据类别，比如多选标签，复选框等，需要更进一步的补充PROPERTY_TYPE的类别。这个脚本可以作为一个基础的模板，可以根据实际需求进行修改以及更深度的扩展。

另外notion api里面只开放了数据库的读写操作，不支持对单条数据的删除。所以在实际使用的时候，最多只能清空数据行，而不能完全删除。

## Ref

- [source code](https://gist.github.com/YeeKal/59c85ec768857fe707d3fe4b587a49bd)