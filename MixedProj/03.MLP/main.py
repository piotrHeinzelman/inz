# https://keras.io/examples/vision/mnist_convnet/
# https://keras.io/getting_started/ 
# https://keras.io/guides/sequential_model/
# https://keras.io/guides/functional_api/

import numpy as np
import time
import matplotlib.pyplot as plt

import keras
from keras import layers



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


percent=100
num_classes = 10

trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )

# Scale images to the [0, 1] range
trainX = trainX.astype("float32") # / 255
testX = testX.astype("float32") # / 255
trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
testX = testX.reshape(1*percent*100, 784).astype("float32") / 255

# convert class vectors to binary class matrices
trainY = keras.utils.to_categorical(trainY, num_classes)
testY = keras.utils.to_categorical(testY, num_classes)



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


# Model / data parameters
num_classes = 10

inputs = keras.Input(shape=(784,))

dense = layers.Dense(64, activation="sigmoid")
x1 = dense(inputs)
x2 = layers.Dense(64, activation="sigmoid")(x1)
outputs = layers.Dense(10, activation="softmax")(x2)

model = keras.Model(inputs=inputs, outputs=outputs, name="mnist_model")

if (False):
    model.summary()


# Train the model
epochs = 500


model.compile(
    loss='binary_crossentropy',
    metrics=["accuracy"],
)


# model.compile(optimizer='sgd', loss='binary_crossentropy', metrics=[keras.metrics.Accuracy()])


start=time.time()
for i in range(10):
    history = model.fit(trainX, trainY, batch_size=6*100*percent, epochs=epochs, validation_split=0.2, verbose=0)

end=time.time()
d=end-start
print("# Time: " , d)



test_scores = model.evaluate(testX, testY, verbose=2)
print("Test loss:", test_scores[0])
print("Test accuracy:", test_scores[1])






