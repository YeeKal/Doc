---
 title: sklearn_01
 categories: python
 tags: sklearn
 date: 2019-06-15
---

## intro to sklearn

[machine learning map](https://scikit-learn.org/stable/tutorial/machine_learning_map/index.html)

#### datasets

[sklearn.datasets](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.datasets) module includes utilities to load datasets, including methods to load and fetch popular reference datasets. It also features some artificial data generators.

```python
#load iris dataset
from sklearn.datasets import load_iris
data = load_iris()
data_X = data.data
data_y = data.target 


# load Boston house price
from sklearn import datasets
loaded_data = datasets.load_boston()
#导入数据
data_X = loaded_data.data
data_y = loaded_data.target

```
#### 通用学习模式

```python
# 通用学习模式
model = KNeighborsClassifier()
model.fit(X_train, y_train)
model.score(x_test,y_test) #Return the mean accuracy on the given test data and labels.
print(model.predict(X_test))
print(y_test)

# model parameters
model.coef_
model.intercept_
model.get_params()
model.score(data_X, data_y) #coefficient of determination

# 预测结果
knn = KNeighborsClassifier()
knn.fit(X_train, Y_train)
predictions = knn.predict(X_validation)
print(predictions)
print(accuracy_score(Y_validation, predictions))
print(confusion_matrix(Y_validation, predictions))
print(classification_report(Y_validation, predictions))


# 交叉验证
result=model_selection.cross_val_score(knn, X_train, Y_train, cv=5)
print(result.mean())


#保存模型
#保存Model(注:save文件夹要预先建立，否则会报错)
with open('save/clf.pickle', 'wb') as f:
    pickle.dump(clf, f)

#读取Model
with open('save/clf.pickle', 'rb') as f:
    clf2 = pickle.load(f)
    #测试读取后的Model
    print(clf2.predict(X[0:1]))


#使用jopblib保存模型
from sklearn.externals import joblib #jbolib模块
#保存Model(注:save文件夹要预先建立，否则会报错)
joblib.dump(clf, 'save/clf.pkl')
#读取Model
clf3 = joblib.load('save/clf.pkl')
#测试读取后的Model
print(clf3.predict(X[0:1]))
```

#### 文本类别编码

简单数字映射

```python
from sklearn.preprocessing import LabelEncoder

sex=df_train['Sex']
encoder=LabelEncoder()
sex_encoded=encoder.fit_transform(sex)
print(sex_encoded)
print(sex)

print(encoder.classes_)# 查看编码映射
```

独热编码

```python
from sklearn.preprocessing import OneHotEncoder

encoder2=OneHotEncoder()
sex_hot=encoder2.fit_transform(sex_encoded.reshape(-1,1))
print(sex_hot)
    '''
    <891x2 sparse matrix of type '<class 'numpy.float64'>'
        with 891 stored elements in Compressed Sparse Row format>
    # 这是SciPy中的稀疏矩阵，每一行仅有一个是1,使用sex_hot.toarray()转换为Numpy数组
    '''

```

合并上述两个编码
```python
from sklearn.preprocessing import LabelBinarizer

sex=df_train['Sex']
encoder=LabelBinarizer()
sex_encoded=encoder.fit_transform(sex)
#通过sparse_output=True给LabelBinarizer构造函数，可以得到稀疏矩阵
```

[常用机器学习实践技巧](https://zhuanlan.zhihu.com/p/50444108)

