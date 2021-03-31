---
 title: pandas
 categories: python
 tags: pandas
 date: 2019-12-30
---

```python
df.head()
df.info()
df.tail()
df_train.describe() #统计 min/std/max/mean
df.count() #计算每个类别的数目
df.isnull() #显示nan数据

iloc[1:10] # 按照逻辑行索引
pd.loc[] # 行访问数据，可以切片， 按照标签行
pd.iloc[].at[]
pd.iloc[].iat[]
pd.columns # 列名
pd.shape # (row_num,column_num)
```

pandas dataframe 与np.array相互转换
```python
# dataframe--> array
df.values
df.as_matrix()
np.array(df)

# array--> dataframe
df = pd.DataFrame(array)

## plot
df.hist()

from pandas.plotting import scatter_matrix
attri=['Survived','Pclass','Age','SibSp','Parch','Fare']
scatter_matrix(df[attri])
```

数据清洗
```python
'''
以下所有函数都不对df本身作修改
'''
df.dropna(subset=['Cabin']) #放弃有nan的一行
df.drop('Cabin',axis=1)# 丢弃Cabin这一列
#以某个数字（中位数）填充
median = housing["total_bedrooms"].median()
housing["total_bedrooms"].fillna(median) # option 3
```
## ref
- [pandas中DataFrame类型数据操作函数](https://blog.csdn.net/LY_ysys629/article/details/54428838)