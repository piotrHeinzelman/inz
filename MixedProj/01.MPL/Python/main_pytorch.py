# code from: https://www.datacamp.com/tutorial/pytorch-cnn-tutorial

import numpy as np
#import pandas as pd
#import matplotlib.pyplot as plt


import torch
from torch import optim
from torch import nn
from torch.utils.data import DataLoader
from tqdm import tqdm

# !pip install torchvision
import torchvision

import torch.nn.functional as F
import torchvision.datasets as datasets
import torchvision.transforms as transforms

# !pip install torchmetrics
#import torchmetrics
from torchmetrics import Accuracy

#from torcheval.metrics import MulticlassAccuracy


import inspect
import os
import time


#os.environ["PYTORCH_CUDA_ALLOC_CONF"] = "caching_allocator"
os.environ["PYTORCH_CUDA_ALLOC_CONF"] = "max_split_size_mb:128"



if torch.cuda.is_available():
  print("CUDA available. Using GPU acceleration.")
  device = "cuda"
else:
  print("CUDA is NOT available. Using CPU for training.")
  device = "cpu"




# params
epochs = 5
percent = 10 # 90 
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



trainX = readFileX ('../data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('../data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('../data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('../data/t10k-labels-idx1-ubyte', 8, percent, 1 )


trainX = trainX.astype("float32")
testX = testX.astype("float32")

trainY = trainY.astype("int")
testY = testY.astype("int")

trainX = trainX.reshape(6*percent*100, 1, 28,28).astype("float32") / 255
testX = testX.reshape(1*percent*100, 1, 28,28).astype("float32") / 255

 
class MLP(nn.Module):
   def __init__(self, in_channels, num_classes):

 
       super(MLP, self).__init__()

       # 1st convolutional layer
       self.fc0 = nn.Linear( 784, 64 ) 
       self.fc1 = nn.Linear( 64, 64 ) #  self.fc1 = nn.Linear( 64, num_classes) in, out
       self.fc2 = nn.Linear( 64, num_classes )

   def forward(self, x):
       x = self.fc0(x)
       x = self.fc1(x)            # Apply fully connected layer
       x = self.fc2(x)            # Apply fully connected layer
       return x




device = "cuda" if torch.cuda.is_available() else "cpu"
print(device)

modelCPU = MLP(in_channels=1, num_classes=10)
model = modelCPU.to(device)


# Define the loss function
criterion = nn.CrossEntropyLoss()

# Define the optimizer
optimizer = optim.Adam(model.parameters(), lr=0.001)

print( trainX.shape )
print( trainY[0] )


data = torch.tensor( trainX , device=device)
targets = torch.tensor(trainY, device=device)

start=time.time()


for epoch in range(epochs):
   scores = model(data)
   loss = criterion(scores, targets)
   optimizer.zero_grad()
   loss.backward()
   optimizer.step()
   # print( loss )

end=time.time()

print(scores[0].shape)
print(scores[1])

end=time.time()
d=end-start
print("# Python PyTorch 2.0 60000 Images, Epoch:",epoch,", Time: ", d)





# Set up of multiclass accuracy metric
acc = Accuracy(task="multiclass",num_classes=10).to(device)

# Iterate over the dataset batches
model.eval()


dataTest = torch.tensor( testX , device=device)
targetsTest = torch.tensor(testY, device=device)

with torch.no_grad():
   outputs = model(dataTest)
   _, preds = torch.max(outputs, 1)
   preds = preds.to(device)
   acc(preds, targetsTest)

test_accuracy = acc.compute()
print(f"Test accuracy: {test_accuracy}")

