---
 title: 推荐系统中的向量检索00-概述
 categories: recsys
 tags: recsys
 date: 2020-10-25
---

- embedding-based retrieval: 
    - 检索：语义检索/语义召回/向量召回/向量检索/
    - 匹配： 文本匹配/语义匹配
    - 中英名称并没有统一的叫法。
    - [语义/向量][检索/索引/匹配]一般指两大类应用:
        - 应用于文本：这类方法更加丰富多样，参考[MatchZoo-py](https://github.com/NTMC-Community/MatchZoo-py)
        - 应用于各种实体的：工业应用场景较多，比如电商(淘宝，京东，amazon)，社交(facebook)等。可以说在有推荐/搜索的地方都可以应用。本笔记专注于**针对搜索推荐场景的向量检索**。
- 检索对象/术语：
    - doc/query, user/item
- 向量检索的三大方法：
    - 双塔模型(two tower model): doc和query分别训练，由于模型分离，便于在doc端建索引，使用ann方法召回。
    - 单塔模型：doc和query有特征交互，复杂度增大。 如阿里的tdm
    - 图模型(graph embedding)：图神经网络学习，最后用ann召回


- dssm/wide&deep/wide&cross/ ali mind
- graph embedding







## 特征处理

- labelEncoding: 离散特征编程数字
- OneHotEncoding
- HashEncoding
    - hash trick
    - hash 冲突
- embedding
    - 多值离散特征: 相加，平均
    - 多个特征： 拼接

## ref

- blog
    - [Semantic Re-ranking](https://github.com/caiyinqiong/Semantic-Ranking-Models/blob/main/semantic%20reranking.md)
    - [召回，排序算法相关论文笔记](https://www.zhihu.com/column/c_1098542257317171200)
    - [《搜索与推荐中的深度学习匹配》之搜索篇](https://zhuanlan.zhihu.com/p/38296950)
- open project
    - [MatchZoo-py](https://github.com/NTMC-Community/MatchZoo-py)




