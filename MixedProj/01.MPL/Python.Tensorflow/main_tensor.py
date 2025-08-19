
# https://keras.io/examples/vision/mnist_convnet
# https://www.tensorflow.org/?hl=pl
# https://www.osc.edu/resources/getting_started/howto/howto_use_gpu_in_python
# https://docs.conda.io/projects/conda/en/latest/user-guide/getting-started.html
# https://www.tensorflow.org/api_docs/python/tf/keras/Sequential
# https://devdocs.io/tensorflow~2.4/keras/activations

# tensorflow==2.14.0  ===>>>  cuda-12.* (cuda-12.1, cuda-12.2)
# https://keras.io/getting_started/
# https://keras.io/2/api/models/sequential/


import tensorflow as tf


#import numpy as np
import time
#from tensorflow.keras.backend import clear_session
#from tensorflow import keras

import numpy as np


physical_devices = tf.config.list_physical_devices('GPU')
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)
      print(gpu.device_type)

device_name = tf.test.gpu_device_name()
print(device_name)

# params
epochs = 5000 # 5000
percent = 100
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

timeLoadDataStart=time.time()

trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )


trainX = trainX.astype("float32") # / 255
testX = testX.astype("float32") # / 255
trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
testX = testX.reshape(1*percent*100, 784).astype("float32") / 255

timeLoadDataEnd=time.time()


# Model / data parameters
num_classes = 10
input_shape = (784, 1)


model = tf.keras.Sequential()
model.add(tf.keras.layers.Input(shape=(784,)))
model.add(tf.keras.layers.Dense(64, activation='sigmoid'))
model.add(tf.keras.layers.Dense(64, activation='sigmoid'))
model.add(tf.keras.layers.Dense(10, activation='softmax'))


opt = tf.keras.optimizers.SGD( learning_rate=0.1, momentum=0.0 )
#cce = tf.keras.losses.CategoricalCrossentropy()
cce = tf.keras.losses.SparseCategoricalCrossentropy()

model.compile(optimizer=opt, loss=cce, metrics=['accuracy'])

model.summary()



timeTrainStart=time.time()

with tf.device('/device:GPU:0'):
   model.fit( trainX, trainY, epochs=epochs, verbose=0, batch_size=60000 ) #

timeTrainEnd=time.time()

timeForwardStart=time.time()

with tf.device('/device:GPU:0'):
   result = model.evaluate( testX, testY )

timeForwardEnd=time.time()



loss, acc = model.evaluate( testX, testY )
print("Loss {}, Accuracy {}".format(loss, acc))


print('# Python, MLP: 2x 64 Neu, data size=',percent*600,'' );
print('# train: epochs=',epochs,', time=',timeTrainEnd-timeTrainStart,'[s], one epoch time=',(timeTrainEnd-timeTrainStart)/(epochs),'[s], one forward&backward time=',(timeTrainEnd-timeTrainStart)/(epochs*percent*0.6),'[ms]' );
print('# accuracy=',result[1],', forward one epoch time=',timeForwardEnd-timeForwardStart,'[s], one propagation time=',(timeForwardEnd-timeForwardStart)/(percent/10),'[ms]'  );

print ('# LoadDataTime=', timeLoadDataEnd-timeLoadDataStart,'[s]')

