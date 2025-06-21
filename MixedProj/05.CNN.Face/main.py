import tensorflow as tf
import numpy as np
from tensorflow import keras

import os
import time
#from tensorflow.keras.backend import clear_session

device_name = tf.test.gpu_device_name()
print(device_name)

#from keras import backend as K
#K.tensorflow_backend._get_available_gpus()


physical_devices = tf.config.list_physical_devices('GPU')
print(physical_devices)
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)

# params
epochs = 100
num_classes = 10


def readFileX ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    data=np.fromfile( fileName, np.uint8, num_classes*multi*227*227*3, '' )
    data=data.reshape(num_classes*multi, 227, 227, 3)
    file.close()
    return data

def readFileY ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    len=num_classes*multi
    data=np.fromfile( fileName, np.uint8, len, '' )
    file.close()
    return data



# padding: "valid" - no padding
# padding: "same" - same input and output (if stride=1)


def AlexNet():
   NUMBER_OF_CLASSES = 10
   return keras.models.Sequential([
      keras.layers.Input(shape=( 227, 227, 3 )),

      keras.layers.Conv2D(name='conv1', filters=96, kernel_size=(11,11), activation='relu', strides=(4,4) ), 
      keras.layers.BatchNormalization(),
      keras.layers.MaxPool2D(pool_size=(3,3), strides=(2,2)),

      keras.layers.Conv2D(name='conv2', filters=256, kernel_size=(5,5), activation='relu', strides=(1,1), padding='valid' ),
      keras.layers.BatchNormalization(),
      keras.layers.MaxPool2D(pool_size=(3,3), strides=(2,2)),


      keras.layers.Conv2D(name='conv3', filters=384, kernel_size=(3,3), activation='relu', strides=(1,1), padding='valid' ),

      keras.layers.Conv2D(name='conv4', filters=256, kernel_size=(3,3), activation='relu', strides=(1,1), padding='valid' ),

      keras.layers.Conv2D(name='conv5', filters=256, kernel_size=(3,3), activation='relu', strides=(1,1), padding='valid' ),
      keras.layers.MaxPool2D(pool_size=(3,3), strides=(2,2)),

      keras.layers.Flatten(),
      keras.layers.Dense(4096, activation='relu'),
      keras.layers.Dropout( .5 ),
      keras.layers.Dense(4096, activation='relu'),
      keras.layers.Dense(10, activation='softmax')
])

trainX = readFileX ('data/trainX', 15 )
trainY = readFileY ('data/trainY', 15 )
testX = readFileX ('data/testX', 5  )
testY = readFileY ('data/testY', 5 )


trainY = trainY.astype("int")
testY = testY.astype("int")

# print( "trainX[0].shape" )
# print( trainX[0].shape )
# print( "trainX[0]" )
# print( trainX[0] )



model = AlexNet()
#model.summary()


# print ( trainY.shape )
# print ( trainY[2])



model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])

start=time.time()

with tf.device('/device:GPU:0'):
    model.fit(trainX, trainY, epochs=epochs, verbose=0)

end=time.time()
d=end-start


print("# Python Tensorflow Time: " , d)

score = model.evaluate(trainX, trainY, verbose=0 )
print("Train loss:", score[0])
print("Train accuracy:", score[1])


score = model.evaluate(testX, testY, verbose=0 )
print("Test loss:", score[0])
print("Test accuracy:", score[1])



#clear_session()


# 1 FC 396 sec train: accuracy 1, test acc 0.04
