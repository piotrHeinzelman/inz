# from Python - Machine learning i deep learning ISBN: 978-83-283-7001-2
# https://scikit-learn.org/dev/modules/generated/sklearn.neural_network.MLPClassifier.html

import numpy as np
import time
import datetime
import sys
import struct
import sklearn.neural_network as snn



def readFileX ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    data=np.fromfile( fileName, np.uint8, percent*600*784, '', offset )
    data=data.reshape(percent*100*multi, 784)
    data=(data/16)
    file.close()
    return data

def readFileY ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    data=np.fromfile( fileName, np.uint8, percent*100*multi, '', offset )
    file.close()
    return data


percent=1
trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )

#print ( trainX[0] )
#print ( trainY )
#print ( testX[0] )
#print ( testY )

#  'data/t10k-images-idx3-ubyte'
#  'data/t10k-labels-idx1-ubyte'
#  'data/train-images-idx3-ubyte'
#  'data/train-labels-idx1-ubyte'

net = snn.MLPClassifier(hidden_layer_sizes=(64,64,10), activation='logistic', solver='sgd', alpha=0.0001, learning_rate='constant', learning_rate_init=0.001)
net.fit(trainX, trainY)

print (net)







