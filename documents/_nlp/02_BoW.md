---
 title: 01-Bow
 categories: nlp
 tags: nlp
 date: 2020-06-17
---

## 文本表示 (text representation)

句子作为基本的语义单位，相当于机器学习中的一个单位量。而这个单位量的特征则由组合成句子的词以及词的顺序构成。众多语言模型的作用就是如何用数学语言描述一个词，以及由词构成的句子，把一个语义单位转换为一个高维向量。在完成了句子向向量转化的过程之后，就可以对语句像图片一样进行各种分类，识别，学习。

**词袋模型**(BoW, bag of words)将词频作为词的数学特征，根据各个词的词频构成整个句子的向量特征。所谓”词袋“是指对于一个文本忽略其词序和语法，句法，将其仅仅看做是一个词集合;文本中每个词的出现都是独立的，不依赖于其他词是否出现;每个句子就像装着各个独立的词的袋子一样。这也被称为文本的离散表示。

##  词袋模型

- [zhihu-文本表示之词袋模型](https://zhuanlan.zhihu.com/p/53302305)

统计各个语素中的词频：
```python
'''
John likes to watch movies. Mary likes too.
John also likes to watch football games.
 |
 v
 {"John": 1, "likes": 2,"to": 3, "watch": 4, "movies": 5,"also": 6, "football": 7, "games": 8,"Mary": 9, "too": 10}
'''
```

词频的三种统计方式：
1. 0/1： 出现的词频率为1,不出现为0。只强调了出现词与未出现词的差异(在有些短文本分类中可能会表现很好)，对于出现词之间的差异未体现
2. TF(term frequency)： 统计真实的词频。长文本比短文本对每个单词有更高的出现次数，尽管他们可能在描述同一个主题
3. IDF(inverse document frequency): 各文档中每个单词的出现次数除以该文档中所有单词的总数。在此基础上，给每个词分配一个权重(降低常用词的影响)，训练集中很多文档中均出现的词给予较小权重，只在很少文档中出现的词给予较大权重，这个权重叫逆文档频率.
    $$IDF(w)=log(\frac{文档总数}{包含该词的文档数+1})$$
4. TF*IDF: 词频与权重相乘

词袋模型步骤：
1. tokenizing: 分词
2. counting: 统计
3. normalizing: 正则化

```python
# scikit-learn API

# 0/1
from sklearn.feature_extraction.text import CountVectorizer
vectorizer = CountVectorizer(binary=True)
# TF
from sklearn.feature_extraction.text import CountVectorizer
vectorizer = CountVectorizer()
# IDF
from sklearn.feature_extraction.text import TfidfVectorizer
vectorizer = TfidfVectorizer(norm='l2', use_idf=False, sublinear_tf=True)
# TF*TDF
from sklearn.feature_extraction.text import TfidfVectorizer
vectorizer = TfidfVectorizer(stop_words=['你','我','它'],max_df=0.9, use_idf=True, sublinear_tf=True, smooth_idf=True)


# example-IDF
from sklearn.feature_extraction.text import TfidfVectorizer
corpus = [
    'This is the first document.',
    'This document is the second document.',
    'And this is the third one.',
    'Is this the first document?',
]
vectorizer = TfidfVectorizer()
X = vectorizer.fit_transform(corpus)
print(vectorizer.get_feature_names())
print(X)
print(X.toarray())

'''
['and', 'document', 'first', 'is', 'one', 'second', 'the', 'third', 'this']
  (0, 1)	0.46979138557992045
  (0, 2)	0.5802858236844359
  (0, 6)	0.38408524091481483
  (0, 3)	0.38408524091481483
  (0, 8)	0.38408524091481483
  (1, 5)	0.5386476208856763
  (1, 1)	0.6876235979836938
  (1, 6)	0.281088674033753
  (1, 3)	0.281088674033753
  (1, 8)	0.281088674033753
  (2, 4)	0.511848512707169
  (2, 7)	0.511848512707169
  (2, 0)	0.511848512707169
  (2, 6)	0.267103787642168
  (2, 3)	0.267103787642168
  (2, 8)	0.267103787642168
  (3, 1)	0.46979138557992045
  (3, 2)	0.5802858236844359
  (3, 6)	0.38408524091481483
  (3, 3)	0.38408524091481483
  (3, 8)	0.38408524091481483
[[0.         0.46979139 0.58028582 0.38408524 0.         0.
  0.38408524 0.         0.38408524]
 [0.         0.6876236  0.         0.28108867 0.         0.53864762
  0.28108867 0.         0.28108867]
 [0.51184851 0.         0.         0.26710379 0.51184851 0.
  0.26710379 0.51184851 0.26710379]
 [0.         0.46979139 0.58028582 0.38408524 0.         0.
  0.38408524 0.         0.38408524]]
'''

```

词袋模型提供了文本数字化的一种方式，这种方式的结果是文本与词频的对应关系，这样就为后续的文本训练提供了原始的数据支撑。

如果文档很多，整个文集中不同单词的数量非常大，而单个文档使用的单词数量远远少于总体词袋单词个数。tf-idf向量维度会非常大而且每个向量中大多数的值为 0 。此时词袋模型得到的向量是 高维稀疏数据。改进方式：采用词的分布式表示，如word2vec,Glove等。


## n-gram

词袋模型假设字与字之间相互独立，而n-gram（n元语法）是从一个句子中提取n个连续的字的集合，以获取到字的前后信息。一般2-gram或者3-gram比较常见。

比如“邓紫棋太可爱了，我爱邓紫棋”，“我要看邓紫棋的演唱会”这两个句子，分解为2-gram词汇表：
>｛邓，邓紫，紫，紫棋，棋，棋太，太，太可，可，可爱，爱，爱了，了，了我，我，我爱，爱邓，我要，要，要看，看邓，棋的，的，的演，演，演唱，唱会，会｝

这种表示方法的好处是可以获取更丰富的特征，提取字的前后信息，考虑了字之间的顺序性。但是问题也是显而易见的，这种方法没有解决数据稀疏和词表维度过高的问题，而且随着n的增大，词表维度会变得更高。
