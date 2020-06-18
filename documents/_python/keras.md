---
 title: keras
 categories: python
 tags: keras
 date: 2019-12-15
---


[Getting started with Keras](https://keras.io/getting-started/sequential-model-guide/)


construction
```python
from keras.models import Sequential
from keras.layers import Dense, Activation

model = Sequential([
    Dense(32, input_shape=(784,)),
    Activation('relu'),
    Dense(10),
    Activation('softmax'),
])

## or 
model = Sequential()
model.add(Dense(32, input_dim=784))
model.add(Activation('relu'))


## specify the input shape
model = Sequential()
model.add(Dense(32, input_shape=(784,)))
# or
model = Sequential()
model.add(Dense(32, input_dim=784))
```
Compilation

- an optimizer: the string identifier of an existing optimizer, or an instance of the Optimizer class
- a loss function: the string identifier of an existing loss function 
- a list of metrics: the string identifier of an existing metric or a custom metric function

```python
# For a multi-class classification problem
model.compile(optimizer='rmsprop',
              loss='categorical_crossentropy',
              metrics=['accuracy'])

# For a binary classification problem
model.compile(optimizer='rmsprop',
              loss='binary_crossentropy',
              metrics=['accuracy'])

# For a mean squared error regression problem
model.compile(optimizer='rmsprop',
              loss='mse')

# For custom metrics
import keras.backend as K

def mean_pred(y_true, y_pred):
    return K.mean(y_pred)

model.compile(optimizer='rmsprop',
              loss='binary_crossentropy',
              metrics=['accuracy', mean_pred])
```

Training

```python
model.fit(data, labels, epochs=10, batch_size=32)
```

Evaluation
```python
score = model.evaluate(x_test, y_test, batch_size=32)
results=model.predict(x_test)
```

Parameters
```python
model.summary() 
model.get_weights()
model.layers.weights/name
```



```python
# 查看搭建的网络
print (model.summary())
```

keras构建网络基本步骤：

```python
# regression
import numpy as np
np.random.seed(1337)  # for reproducibility
from keras.models import Sequential
from keras.layers import Dense
import matplotlib.pyplot as plt # 可视化模块

# create some data
X = np.linspace(-1, 1, 200)
np.random.shuffle(X)    # randomize the data
Y = 0.5 * X + 2 + np.random.normal(0, 0.05, (200, ))
# plot data
plt.scatter(X, Y)
plt.show()

X_train, Y_train = X[:160], Y[:160]     # train 前 160 data points
X_test, Y_test = X[160:], Y[160:]       # test 后 40 data points

##
model=Sequential()
model.add(Dense(output_dim=1,input_dim=1))

model.compile(loss='mse',optimizer='sgd')

print('Training -----------')
for step in range(301):
    cost = model.train_on_batch(X_train, Y_train)
    if step % 100 == 0:
        print('train cost: ', cost)

# test
print('\nTesting ------------')
cost = model.evaluate(X_test, Y_test, batch_size=40)
print('test cost:', cost)
W, b = model.layers[0].get_weights()
print('Weights=', W, '\nbiases=', b)

Y_pred = model.predict(X_test)
plt.scatter(X_test, Y_test)
plt.plot(X_test, Y_pred)
plt.show()

```