# from Python - Machine learning i deep learning ISBN: 978-83-283-7001-2
# https://scikit-learn.org/dev/modules/generated/sklearn.neural_network.MLPClassifier.html

import time
import datetime
import sys
import struct
import sklearn.neural_network as snn
import matplotlib.pyplot as plt
import numpy as np



def readFileX ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    data=np.fromfile( fileName, np.uint8, percent*100*784*multi, '', offset )
    data=data.reshape(percent*100*multi, 784)
    data=1-(data/128)
    file.close()
    return data

def readFileY ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    len=percent*100*multi
    data=np.fromfile( fileName, np.uint8, len, '', offset )

    out=[]
    for i in range ( len ):
        tmp=[0,0,0,0,0,0,0,0,0,0]
        tmp[ data[i]] = 1
        out.append( tmp )
    file.close()
    return out


percent=50
trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )

#print ( trainX[0] )
#print ( trainY )
#print ( testX[0] )
#print ( testY )
#print(testY)

#  'data/t10k-images-idx3-ubyte'
#  'data/t10k-labels-idx1-ubyte'
#  'data/train-images-idx3-ubyte'
#  'data/train-labels-idx1-ubyte'


#print(trainX[0])

if (False):
    fig, ax = plt.subplots( nrows=2, ncols=5, sharex=True, sharey=True )
    ax=ax.flatten()
    img = trainX[0].reshape(28,28)
    ax[0].imshow( img, cmap='Greys' )
    ax[0].set_xticks([])
    ax[0].set_yticks([])
    plt.tight_layout()
    plt.show()




#net = snn.MLPClassifier(hidden_layer_sizes=(64,64,10), activation='logistic', solver='sgd', alpha=0.0001, learning_rate='constant', learning_rate_init=0.001, max_iter=5000 )
net = snn.MLPClassifier( hidden_layer_sizes=(64,64), max_iter=500, random_state=1, alpha=0.0001,  early_stopping=False, activation='logistic', solver='sgd', learning_rate='constant', learning_rate_init=0.001 )

start=time.time()

net.fit( trainX, trainY )

# net.partial_fit( trainX, trainY )
# l.append( net.score(testX, testY) )


end=time.time()
d=end-start
print("# Python Sklearn Time: " , d)
#print("ps[]=" , d)

print ("# Python Sklearn loss:", net.loss_ , ", score: " , net.score( testX, testY ), ", predict: ",net.predict(testX[:1]) )

#resultY = net.predict( testX )


