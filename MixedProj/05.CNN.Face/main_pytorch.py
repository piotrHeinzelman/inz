# import torch
# x = torch.rand(5, 3)
# print(x)

# import torch
# torch.cuda.is_available()

# print ( torch.cuda.is_available() )

# code from:
# https://www.datacamp.com/tutorial/pytorch-cnn-tutorial


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


import torch
from torch import optim
from torch import nn
from torch.utils.data import DataLoader
from torch.utils.data import StackDataset
from tqdm import tqdm

# !pip install torchvision
import torchvision



import torch.nn.functional as F
import torchvision.datasets as datasets
import torchvision.transforms as transforms

# !pip install torchmetrics
import torchmetrics

from torchmetrics import Accuracy


num_classes=10


def readFileX ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    data=np.fromfile( fileName, np.uint8, num_classes*multi*227*227*3, '' )
    data=data.reshape(num_classes*multi, 3,227,227 )
    file.close()
    return data

def readFileY ( fileName ,  multi ):
    file=open( fileName, 'rb' )
    len=num_classes*multi
    data=np.fromfile( fileName, np.uint8, len, '' )
    file.close()
    return data


trainX = readFileX ('data/trainX', 15 )
trainY = readFileY ('data/trainY', 15 )
testX = readFileX ('data/testX', 5  )
testY = readFileY ('data/testY', 5 )


trainY = trainY.astype("int")
testY = testY.astype("int")

images = trainX
texts = trainY



class CNN(nn.Module):
   def __init__(self, in_channels, num_classes):

       """
       Building blocks of convolutional neural network.

       Parameters:
           * in_channels: Number of channels in the input image (for grayscale images, 1)
           * num_classes: Number of classes to predict. In our problem, 10 (i.e digits from  0 to 9).
       """
       super(CNN, self).__init__()

       # 1st convolutional layer
       # self.conv1 = nn.Conv2d(in_channels=in_channels, out_channels=8, kernel_size=3, padding=1)
       self.conv1   = nn.Conv2d( in_channels=3, out_channels=96, kernel_size=11, padding=1, stride=4 )
       # Max pooling layer
       self.pool = nn.MaxPool2d(kernel_size=2, stride=2)
       # 2nd convolutional layer
       self.conv2 = nn.Conv2d(in_channels=96, out_channels=16, kernel_size=3, padding=1)
       # Fully connected layer
       self.fc1 = nn.Linear( 169 , num_classes) #16*7*7

   def forward(self, x):
       """
       Define the forward pass of the neural network.

       Parameters:
           x: Input tensor.

       Returns:
           torch.Tensor
               The output tensor after passing through the network.
       """
       x = F.relu( self.conv1(x) )  # Apply first convolution and ReLU activation
       x = self.pool(x)           # Apply max pooling
       x = F.relu( self.conv2(x) )  # Apply second convolution and ReLU activation
       x = self.pool(x)           # Apply max pooling
       x = x.reshape(x.shape[0], -1)  # Flatten the tensor
       x = self.fc1(x)            # Apply fully connected layer
       return x




device = "cuda" if torch.cuda.is_available() else "cpu"
print ( device )


model = CNN(in_channels=1, num_classes=10).to(device)
print(model)




# Define the loss function
criterion = nn.CrossEntropyLoss()

# Define the optimizer
optimizer = optim.Adam(model.parameters(), lr=0.001)


print( trainY.shape )


num_epochs=10
for epoch in range(num_epochs):
 # Iterate over training batches
   print(f"Epoch [{epoch + 1}/{num_epochs}]")

#   for batch_index, ( data, targets ) in enumerate(tqdm(dataloader_train)):
for batch_index in range ( trainY.size ):
       #print( batch_index )	
       data = torch.Tensor( trainX ) # trainX[ batch_index ]     #train_dataset.to(device)
       data=data.to(device)
       targets = torch.Tensor( trainY )   #train_dataset.to(device)
       # print(data)
       # print(targets)
       scores = model( data )
       loss = criterion( scores, targets )
       optimizer.zero_grad()
       loss.backward()
       optimizer.step()




# Set up of multiclass accuracy metric
acc = Accuracy(task="multiclass",num_classes=num_classes)

# Iterate over the dataset batches
model.eval()
with torch.no_grad():
   for images, labels in range(testY.size):
       # Get predicted probabilities for test data batch
       outputs = model(images)
       _, preds = torch.max(outputs, 1)
       acc(preds, labels)
       precision(preds, labels)
       recall(preds, labels)

#Compute total test accuracy
test_accuracy = acc.compute()
print(f"Test accuracy: {test_accuracy}")




# start=time.time()
# model.fit(trainX, trainY, epochs=epochs, verbose=0)
# end=time.time()
# d=end-start
# print("# PyTorch Time: " , d)
# score = model.evaluate(trainX, trainY, verbose=0 )
# print("Train loss:", score[0])
# print("Train accuracy:", score[1])
# score = model.evaluate(testX, testY, verbose=0 )
# print("Test loss:", score[0])
# print("Test accuracy:", score[1])

#import tensorflow as tf
#import numpy as np
#from tensorflow import keras

#import os
#import time
#from tensorflow.keras.backend import clear_session














####################################


















#   return keras.models.Sequential([
#      keras.layers.Input(shape=( 227, 227, 3 )),
#
#      keras.layers.Conv2D(name='conv1', filters=96, kernel_size=(11,11), activation='relu', strides=(4,4) ), 
#      keras.layers.BatchNormalization(),
#      keras.layers.MaxPool2D(pool_size=(3,3), strides=(2,2)),
#
#      keras.layers.Conv2D(name='conv2', filters=256, kernel_size=(5,5), activation='relu', strides=(1,1), padding='valid' ),
#      keras.layers.BatchNormalization(),
#      keras.layers.MaxPool2D(pool_size=(3,3), strides=(2,2)),
#
#
#      keras.layers.Conv2D(name='conv3', filters=384, kernel_size=(3,3), activation='relu', strides=(1,1), padding='valid' ),
#
#      keras.layers.Conv2D(name='conv4', filters=256, kernel_size=(3,3), activation='relu', strides=(1,1), padding='valid' ),
#
#      keras.layers.Conv2D(name='conv5', filters=256, kernel_size=(3,3), activation='relu', strides=(1,1), padding='valid' ),
#      keras.layers.MaxPool2D(pool_size=(3,3), strides=(2,2)),
#
#      keras.layers.Flatten(),
#      keras.layers.Dense(4096, activation='relu'),
#      keras.layers.Dropout( .5 ),
#      keras.layers.Dense(4096, activation='relu'),
#      keras.layers.Dense(10, activation='softmax')
