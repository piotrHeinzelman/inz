# https://keras.io/examples/vision/mnist_convnet
# https://www.tensorflow.org/?hl=pl

import tensorflow as tf

import numpy as np
import time
import matplotlib.pyplot as plt

tf.config.list_physical_devices('GPU') 
print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))

# params
epochs = 150
cycles=10
percent=10
num_classes = 10
    

mnist = tf.keras.datasets.mnist

(x_train, y_train),(x_test, y_test) = mnist.load_data()
x_train, x_test = x_train / 255.0, x_test / 255.0


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
    
    out=[]
    for i in range ( len ):
#        tmp=[0,0,0,0,0,0,0,0,0,0]
#        tmp[ data[i]] = 1    
#        out.append( tmp )
        out.append( data[i] )        
    file.close()
    return out



trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )


trainX = trainX.astype("float32") # / 255
testX = testX.astype("float32") # / 255
trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
testX = testX.reshape(1*percent*100, 784).astype("float32") / 255


# convert class vectors to binary class matrices
#trainY = keras.utils.to_categorical(trainY, num_classes)
#testY = keras.utils.to_categorical(testY, num_classes)



model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(28,28)),
  tf.keras.layers.Dense(64, activation='sigmoid'),
  tf.keras.layers.Dense(64, activation='sigmoid'),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5)
model.evaluate(x_test, y_test)





exit()









# Scale images to the [0, 1] range
#trainX = trainX.astype("float32") # / 255
#testX = testX.astype("float32") # / 255
#trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
#testX = testX.reshape(1*percent*100, 784).astype("float32") / 255

# convert class vectors to binary class matrices
#trainY = keras.utils.to_categorical(trainY, num_classes)
#testY = keras.utils.to_categorical(testY, num_classes)



if (False):
    print ( trainX[0] )
    print ( trainY[0] )
    print ( testX[0] )
    print ( testY[0] )

if (False):
    fig, ax = plt.subplots( nrows=2, ncols=5, sharex=True, sharey=True )
    ax=ax.flatten()
    img = trainX[0].reshape(28,28)
    ax[0].imshow( img, cmap='Greys' )
    ax[0].set_xticks([])
    ax[0].set_yticks([])
    plt.tight_layout()
    plt.show()


start=time.time()
for i in range(cycles):
    model.fit(trainX, trainY, epochs=epochs, validation_split=0.2, verbose=0)

end=time.time()
d=end-start
print("# Time: " , d)






