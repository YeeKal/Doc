---
 title: keras
 categories: python
 tags: keras
 date: 2019-12-15
---

## Intro

一个Model包含多个Layers，每个Layer有输入和输出，各个Layer由输入输出相连形成Model。

```python
# tf has wrapped keras
import tensorflow as tf
from tensorflow import keras

keras
|- models
|- layers
```

## Model
```
keras
|- models
   |- Model
   |- load_model()
   |- save_model()
|- Sequential
|- layers
```

two ways to get a model
```python
'''
1. 通过多个相连接的Layer的输入输出来构造Model
tf.keras.Model()
- inputs: The input(s) of the model: a keras.Input object or list of keras.Input objects.
- outputs: The output(s) of the model. 
- name: String, the name of the model.
'''
encoder_inputs = Input(shape=(None, num_encoder_tokens))
encoder = LSTM(latent_dim, return_state=True)
encoder_outputs, state_h, state_c = encoder(encoder_inputs)
encoder_states = [state_h, state_c]
model = Model([encoder_inputs, decoder_inputs], encoder_states)

'''
2. 通过Sequential叠加Layer
'''
model = tf.keras.Sequential()
model.add(tf.keras.layers.Dense(8, input_shape=(16,)))
model.add(tf.keras.layers.Dense(4))
```

Model && Sequential API

```python

Sequential.add(layer)
Sequential.pop()    # Removes the last layer in the model.

Model.summary(line_length=None, positions=None, print_fn=None)
Model.get_layer(name=None, index=None)

Model.compile()     # Configures the model for training.
Model.fit()
model.predict()
Model.evaluate()

# model save & serialization
Model.save(
    filepath,
    overwrite=True,
    include_optimizer=True,
    save_format=None,
    signatures=None,
    options=None,
)
model.save('my_model.h5')
model = load_model('my_model.h5')

Model.get_weights()
Model.set_weights(weights)
Model.load_weights()
Model.get_config()  # Returns a dict of  config of the layer
Model.from_config(config, custom_objects=None)
tf.keras.models.model_from_config(config, custom_objects=None)
Model.to_json(**kwargs)
tf.keras.models.model_from_json(json_string, custom_objects=None)
tf.keras.models.clone_model(model, input_tensors=None, clone_function=None)
```

## Layers

```
keras
|- models
   |- Model
   |- load_model()
   |- save_model()
|- Sequential
|- layers
    |- Activation
|- activations
```

A Layer instance is callable, much like a function: given input, and get output. A Layer  is more than a general function, it maintain a state.

Core layers
```python
'''
tf.keras.Input(
    shape=None,
    batch_size=None,
    name=None,
    dtype=None,
    sparse=False,
    tensor=None,
    ragged=False,
    **kwargs
)

shape:
    A shape tuple (integers), not including the batch size. 
    For instance, shape=(32,) indicates that the expected input will be batches of 32-dimensional vectors
'''

x = Input(shape=(32,))

'''
tf.keras.layers.Dense(
    units,
    activation=None,
    use_bias=True,
    kernel_initializer="glorot_uniform",
    bias_initializer="zeros",
    kernel_regularizer=None,
    bias_regularizer=None,
    activity_regularizer=None,
    kernel_constraint=None,
    bias_constraint=None,
    **kwargs
)
Dense operation: output = activation(dot(input, kernel) + bias)
    activation: the element-wise activation function
    kernel: weights
    bias: a bias vector
Dim explain:
    input: (batch_size,d0,d1)
    output: (batch_size,d0,units)  
    weights(kernel): (d1,units) 右乘
'''

'''
tf.keras.layers.Activation(activation, **kwargs)
'''
layer = tf.keras.layers.Activation('relu')
layer = tf.keras.layers.Activation(tf.nn.relu)
output = layer([-3.0, -1.0, 0.0, 2.0])
list(output.numpy())

# general function
Layer.get_weights()
Layer.set_weights(weights)
```

## Activation

usage
```python
# 1. through an Activation layer
model.add(layers.Dense(64))
model.add(layers.Activation(activations.relu))

# 2. through the activation argument
model.add(layers.Dense(64, activation='relu'))
    # or
model.add(layers.Dense(64, activation=activations.relu))

# 3. function call
foo = tf.constant([-10, -5, 0.0, 5, 10], dtype = tf.float32)
tf.keras.activations.relu(foo).numpy()
```

functions: built-in activation function
```python
tf.keras.activations
|- relu:        max(x, 0)
|- softmax:     exp(x) / tf.reduce_sum(exp(x))
|- sigmoid:     1 / (1 + exp(-x))
|- softplus:    log(exp(x)+1)
|- softsign:    x / (abs(x) + 1)
|- tanh:        ((exp(x) - exp(-x))/(exp(x) + exp(-x)))
|- selu:        if x > 0: return scale * x
                if x < 0: return scale * alpha * (exp(x) - 1)
|- elu:     

```

## Layer weight initializers

## ref

- [Getting started with Keras](https://keras.io/getting-started/sequential-model-guide/)
- [keras api](https://keras.io/api/)

## code

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

## save

