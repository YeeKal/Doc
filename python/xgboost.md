---
title: xgboost 入门
categories: code
tags: python
date: 2021-02-28
---

## xgboost 

- [github ](https://github.com/dmlc/xgboost)
- [document](https://xgboost.readthedocs.io/en/latest/get_started.html)
- [XGBoost 中文文档](https://xgboost.apachecn.org/#/docs/3)
- [XGBoost: A Scalable Tree Boosting System【XGB的原著论文】](https://github.com/YZHANG1270/Markdown_pic/blob/master/xgboost/XGB.pdf)
- [Introduction to Boosted Trees【天奇大神的ppt】](https://github.com/YZHANG1270/Markdown_pic/blob/master/xgboost/BoostedTree.pdf)

- install: conda install py-xgboost

## practice

```python
#  https://xgboost.readthedocs.io/en/latest/python/python_intro.html

################## general usage  ##################
import xgboost as xgb
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt

dtrain = xgb.DMatrix('data/agaricus.txt.train')
dtest = xgb.DMatrix('data/agaricus.txt.test')
# specify parameters via map
param = {'max_depth':2, 'eta':1, 'objective':'binary:logistic' }
num_round = 2
model = xgb.train(param, dtrain, num_round)

# make prediction
preds = model.predict(dtest)
y_true=dtest.get_label()
train_predictions = [round(value) for value in preds]
print(accuracy_score(y_true, train_predictions))

# cross validation
num_round=10
errs=xgb.cv(param, dtrain, num_round, nfold=5,metrics={'error'}, seed = 0)
plt.plot(errs["train-error-mean"])
plt.show()

# specify parameters via map
#silent:取0时表示打印出运行时信息，取1时表示以缄默方式运行，不打印运行时信息。缺省值为0
#建议取0，过程中的输出数据有助于理解模型以及调参。另外实际上我设置其为1也通常无法缄默运行

#objective:缺省值 reg:linear 定义学习任务及相应的学习目标，可选目标函数如下：
# “reg:linear” –线性回归。
#“reg:logistic” –逻辑回归。
#“binary:logistic” –二分类的逻辑回归问题，输出为概率。
#“binary:logitraw” –二分类的逻辑回归问题，输出的结果为wTx。
#“count:poisson” –计数问题的poisson回归，输出结果为poisson分布,在poisson回归中，max_delta_step的缺省值为0
#“multi:softmax” –让XGBoost采用softmax目标函数处理多分类问题，同时需要设置参数num_class（类别个数）
#“multi:softprob” –和softmax一样，但是输出的是ndata * nclass的向量，可以将该向量reshape成ndata行nclass列的矩阵。没行数据表示样本所属于每个类别的概率。
#“rank:pairwise” –set XGBoost to do ranking task by minimizing the pairwise loss


################## data  ##################
# 支持numpy/pandas datafram等常见数据格式

#To load a libsvm text file or a XGBoost binary file into DMatrix:
dtrain = xgb.DMatrix('train.svm.txt')
dtest = xgb.DMatrix('test.svm.buffer')

#To load a CSV file into DMatrix:
# label_column specifies the index of the column containing the true label
dtrain = xgb.DMatrix('train.csv?format=csv&label_column=0')
dtest = xgb.DMatrix('test.csv?format=csv&label_column=0')



################## model  ##################
import xgboost as xgb
model = XGBClassifier()
model.fit(X_train, y_train)

XGBClassifier(base_score=0.5, booster='gbtree', colsample_bylevel=1,
       colsample_bytree=1, gamma=0, learning_rate=0.1, max_delta_step=0,
       max_depth=3, min_child_weight=1, missing=None, n_estimators=100,
       n_jobs=1, nthread=None, objective='binary:logistic', random_state=0,
       reg_alpha=0, reg_lambda=1, scale_pos_weight=1, seed=None,
       silent=True, subsample=1)

bst.save_model("data/test.model")
bst.load_model()

################## plotting  ##################
xgb.plot_importance(bst)
pyplot.show()

xgb.plot_tree(bst, num_trees=2) # 输出树结构，需要graphviz

xgb.to_graphviz(bst, num_trees=2)

################## 调参，网格搜索  ##################
from sklearn.model_selection import GridSearchCV
import xgboost as xgb
xgb_model = xgb.XGBRegressor()
clf = GridSearchCV(xgb_model, {'max_depth': [2, 4, 6],
                                'n_estimators': [50, 100, 200]}, verbose=1,
                    n_jobs=2)
clf.fit(X, y)
```

核心api

```python
################## 1. Dmatrix  ##################

################## 2. Booster  ##################

# xgboost数模型的低层封装
# 为了方便人为观察模型结构，而save_model是为了保存模型
dump_model(fout, fmap='', with_stats=False, dump_format='text')

################## 3. learning api  ##################
xgb.train() -> Booster
xgb.cv() # cross validation

################## 4. Scikit-Learn API  ##################
xgb.XGBRegressor()
xgb.XGBClassifier()
xgb.XGBRanker()
xgb.XGBRFRegressor() # XGBoost random forest regression
xgb.XGBRFCClassifier()

Parameters:
    n_estimators (int) – Number of gradient boosted trees. Equivalent to number of boosting rounds.

    max_depth (int) – Maximum tree depth for base learners.

    learning_rate (float) – Boosting learning rate (xgb’s “eta”)

    verbosity (int) – The degree of verbosity. Valid values are 0 (silent) - 3 (debug).

    objective (string or callable) – Specify the learning task and the corresponding learning objective or a custom objective function to be used (see note below).

    booster (string) – Specify which booster to use: gbtree, gblinear or dart.

    tree_method

fit() #fit gradient boosting model
predict()
apply()
save_model()
load_model()
```



## ref

- [XGBOOST使用说明](http://codewithzhangyi.com/2018/06/01/XGBOOST%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E/)