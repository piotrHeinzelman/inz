import tensorflow as tf
import numpy as np
from tensorflow import keras

import os
import time
from tensorflow.keras.backend import clear_session




physical_devices = tf.config.list_physical_devices('GPU')
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)

# params
epochs = 5
num_classes = 10


def readFileX ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    data=np.fromfile( fileName, np.uint8, num_classes*multi*100*75, '' )
    data=data.reshape(num_classes*multi, 100*75)
    file.close()
    return data

def readFileY ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    len=num_classes*multi
    data=np.fromfile( fileName, np.uint8, len, '' )
    file.close()
    return data



def AlexNet():
   NUMBER_OF_CLASSES = 10
   return keras.models.Sequential([
      keras.layers.Input(shape=( 28, 28, 1 )),
#      keras.layers.Conv2D(name='conv1', filters=20, kernel_size=(5,5), activation='relu', input_shape=( 28, 28, 1 )),
      keras.layers.Conv2D(name='conv1', filters=20, kernel_size=(5,5), activation='relu' ),
      keras.layers.BatchNormalization(),
      keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
      keras.layers.Flatten(),
      keras.layers.Dense(64, activation='relu'),
      keras.layers.Dense(10, activation='softmax')
])





trainX = readFileX ('data/trainX', 15 )
trainY = readFileY ('data/trainY', 15 )
testX = readFileX ('data/testX', 5  )
testY = readFileY ('data/testY', 5 )


trainY = trainY.astype("int")
testY = testY.astype("int")

print( trainX[0].shape )
print( trainX[0] )



model = AlexNet()
model.summary()


print ( trainY.shape )
print ( trainY[2])



model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])

start=time.time()

model.fit(trainX, trainY, epochs=epochs, verbose=0)

end=time.time()
d=end-start

clear_session()

print("# Python Tensorflow Time: " , d)


score = model.evaluate(testX, testY, verbose=1 )
print("Test loss:", score[0])
print("Test accuracy:", score[1])




 model.evaluate(testX, testY)



