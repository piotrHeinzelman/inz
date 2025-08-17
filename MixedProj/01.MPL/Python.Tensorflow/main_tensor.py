# https://keras.io/examples/vision/mnist_convnet
# https://www.tensorflow.org/?hl=pl
# https://www.osc.edu/resources/getting_started/howto/howto_use_gpu_in_python
# https://docs.conda.io/projects/conda/en/latest/user-guide/getting-started.html
# https://www.tensorflow.org/api_docs/python/tf/keras/Sequential
# https://devdocs.io/tensorflow~2.4/keras/activations

# tensorflow==2.14.0  ===>>>  cuda-12.* (cuda-12.1, cuda-12.2)
# https://keras.io/getting_started/


import tensorflow as tf

#import numpy as np
#import time
#from tensorflow.keras.backend import clear_session
#from tensorflow import keras

exit()

import numpy as np
import keras
from keras import layers


physical_devices = tf.config.list_physical_devices('GPU')
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)
      print(gpu.device_type)

device_name = tf.test.gpu_device_name()
print(device_name)

exit()
# params
epochs = 50 #  5000
percent = 1
num_classes = 10


def readFileX ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    data=np.fromfile( fileName, np.uint8, percent*100*784*multi, '', offset )
    data=data.reshape(percent*100*multi, 784)
    data=(data/255)
    file.close()
    return data

def readFileY ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    len=percent*100*multi
    data=np.fromfile( fileName, np.uint8, len, '', offset )
    file.close()
    return data



trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )


trainX = trainX.astype("float32") # / 255
testX = testX.astype("float32") # / 255
trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
testX = testX.reshape(1*percent*100, 784).astype("float32") / 255



# Model / data parameters
num_classes = 10
input_shape = (28, 28, 1)

# Load the data and split it between train and test sets
(x_train, y_train), (x_test, y_test) = keras.datasets.mnist.load_data()

# Scale images to the [0, 1] range
x_train = x_train.astype("float32") / 255
x_test = x_test.astype("float32") / 255
# Make sure images have shape (28, 28, 1)
x_train = np.expand_dims(x_train, -1)
x_test = np.expand_dims(x_test, -1)
print("x_train shape:", x_train.shape)
print(x_train.shape[0], "train samples")
print(x_test.shape[0], "test samples")


# convert class vectors to binary class matrices
y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)


# Model / data parameters
num_classes = 10
input_shape = (28, 28, 1)

# Load the data and split it between train and test sets
(x_train, y_train), (x_test, y_test) = keras.datasets.mnist.load_data()

# Scale images to the [0, 1] range
x_train = x_train.astype("float32") / 255
x_test = x_test.astype("float32") / 255
# Make sure images have shape (28, 28, 1)
x_train = np.expand_dims(x_train, -1)
x_test = np.expand_dims(x_test, -1)
print("x_train shape:", x_train.shape)
print(x_train.shape[0], "train samples")
print(x_test.shape[0], "test samples")


# convert class vectors to binary class matrices
y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)







model = keras.Sequential(
    [
        keras.Input(shape=input_shape),
        layers.Conv2D(32, kernel_size=(3, 3), activation="relu"),
        layers.MaxPooling2D(pool_size=(2, 2)),
        layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
        layers.MaxPooling2D(pool_size=(2, 2)),
        layers.Flatten(),
        layers.Dropout(0.5),
        layers.Dense(num_classes, activation="softmax"),
    ]
)

model.summary()









batch_size = 128
epochs = 15

model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])

model.fit(x_train, y_train, batch_size=batch_size, epochs=epochs, validation_split=0.1)



#model = tf.keras.models.Sequential([
#    tf.keras.layers.Input(shape=(784,)),
#    tf.keras.layers.Dense(64, activation='sigmoid'),
#    tf.keras.layers.Dense(64, activation='sigmoid'),
#    tf.keras.layers.Dropout(0.2),
#    tf.keras.layers.Dense(10, activation='softmax')
#])


exit()


model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])


timeTrainStart=time.time()

with tf.device('/device:GPU:0'):
   model.fit(trainX, trainY, epochs=epochs, verbose=0) # , batch_size=None

timeTrainEnd=time.time()

timeForwardStart=time.time()
with tf.device('/device:GPU:0'):
   result = model.evaluate(testX, testY)

timeForwardEnd=time.time()

clear_session()


print('# Python, MLP: 2x 64 Neu, data size=',percent*600,'' );
print('# train: epochs=',epochs,', time=',timeTrainEnd-timeTrainStart,'[s], one epoch time=',(timeTrainEnd-timeTrainStart)/(epochs),'[s], one forward&backward time=',(timeTrainEnd-timeTrainStart)/(epochs*percent*0.6),'[ms]' );
print('# accuracy=',result[1],', forward one epoch time=',timeForwardEnd-timeForwardStart,'[s], one propagation time=',(timeForwardEnd-timeForwardStart)/(percent/10),'[ms]'  );




# I tensorflow/stream_executor/cuda/cuda_blas.cc:1614]
