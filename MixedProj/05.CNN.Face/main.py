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
from matplotlib import pyplot as plt
from matplotlib import image as mpimg


from sklearn.metrics import classification_report, confusion_matrix, roc_curve, auc



physical_devices = tf.config.list_physical_devices('GPU')
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)

# params
epochs = 500
num_classes = 10


def readFileX ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    data=np.fromfile( fileName, np.uint8, num_classes*multi*100*75, '' )
    data=data.reshape(num_classes*multi, 100*75)
    #data=(data/255)
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
#      keras.layers.Dense(64, activation='relu'),
#      keras.layers.Dropout(0.2),
      keras.layers.Dense(10, activation='softmax')
])





trainX = readFileX ('data/trainX', 15 )
trainY = readFileY ('data/trainY', 15 )
testX = readFileX ('data/testX', 5  )
testY = readFileY ('data/testY', 5 )


#trainX = trainX.astype("float32")
#testX = testX.astype("float32")

trainY = trainY.astype("int")
testY = testY.astype("int")


# trainX = trainX.reshape(6*percent*100, 28,28).astype("float32") / 255
# testX = testX.reshape(1*percent*100, 28,28).astype("float32") / 255

print( trainX[0].shape )
print( trainX[0] )



#image = mpimg.imread("sheep.png")
plt.imshow( trainX[0].reshape(75,100) )
plt.show()  # Displays the image in a graphical format.



model = AlexNet()
model.summary()

# --- flat to 1 item ---
# print ( trainX.shape )
# trainX = np.array_split( trainX, 30000 )
# trainX = trainX[0]
# print ( trainX.shape )

# --- flat to 1 item ---

# trainY = trainY[0]
print ( trainY.shape )
print ( trainY[2])




#trainX = trainX.reshape(1,28,28)


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


score = model.evaluate(testX, testY, verbose=1 )
print("Test loss:", score[0])
print("Test accuracy:", score[1])




# model.evaluate(testX, testY)



