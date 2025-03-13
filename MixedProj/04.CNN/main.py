# https://keras.io/examples/vision/mnist_convnet
# https://www.tensorflow.org/?hl=pl
# https://www.osc.edu/resources/getting_started/howto/howto_use_gpu_in_python
# https://docs.conda.io/projects/conda/en/latest/user-guide/getting-started.html




import tensorflow as tf
import numpy as np
from tensorflow import keras

import os
import time
from tensorflow.keras.backend import clear_session
import matplotlib.pyplot as plt

from sklearn.metrics import classification_report, confusion_matrix, roc_curve, auc







physical_devices = tf.config.list_physical_devices('GPU')
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)

# params
epochs = 500
percent = 50
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



def AlexNet():
   NUMBER_OF_CLASSES = 10
   return keras.models.Sequential([
      keras.layers.Conv2D(name='conv1', filters=20, kernel_size=(5,5), activation='relu', input_shape=(28,28,1)),
      keras.layers.BatchNormalization(),
      keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
      keras.layers.Dense(64, activation='relu'),
      keras.layers.Dense(64, activation='relu'),
      keras.layers.Dropout(0.2),
      keras.layers.Dense(10, activation='softmax')
])





trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )


trainX = trainX.astype("float32") # / 255
testX = testX.astype("float32") # / 255
#trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
trainX = trainX.reshape(6*percent*100, 28,28).astype("float32") / 255
#testX = testX.reshape(1*percent*100, 784).astype("float32") / 255
testX = testX.reshape(1*percent*100, 28,28).astype("float32") / 255




model = AlexNet()

#model = tf.keras.models.Sequential([
#  tf.keras.layers.Input(shape=(784,)),
#  tf.keras.layers.Dense(64, activation='sigmoid'),
#  tf.keras.layers.Dense(64, activation='sigmoid'),
#  tf.keras.layers.Dropout(0.2),
#  tf.keras.layers.Dense(10, activation='softmax')
#])

model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])

start=time.time()

model.fit(trainX, trainY, epochs=epochs, verbose=0)

end=time.time()
d=end-start

clear_session()


print("# Python Tensorflow Time: " , d)



# model.evaluate(testX, testY)



