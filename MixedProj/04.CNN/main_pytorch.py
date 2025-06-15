# code from: https://www.datacamp.com/tutorial/pytorch-cnn-tutorial

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


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
import torchmetrics
from torchmetrics import Accuracy

from torcheval.metrics import MulticlassAccuracy


import inspect
import os
import time


num_epochs=5
batch_size = 1

train_dataset = datasets.MNIST(root="data/", download=True, train=True, transform=transforms.ToTensor())
train_loader = DataLoader(dataset=train_dataset, batch_size=batch_size, shuffle=True)
test_dataset = datasets.MNIST(root="datas/", download=True, train=False, transform=transforms.ToTensor())
test_loader = DataLoader(dataset=test_dataset, batch_size=batch_size, shuffle=True)




#def imshow(img):
#   npimg = img.numpy()
#   plt.imshow(np.transpose(npimg, (1, 2, 0)))
#   plt.show()

# get some random training images
#dataiter = iter(train_loader) #dataiter = iter(dataloader_train)
#images, labels = next(dataiter)
#labels
#show images
#imshow(torchvision.utils.make_grid(images))




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
       self.conv1 = nn.Conv2d(in_channels=in_channels, out_channels=20, kernel_size=5, padding=1)
       self.norm  = nn.BatchNorm2d(20)
       # Max pooling layer
       self.pool = nn.MaxPool2d(kernel_size=2, stride=2)
       # 2nd convolutional layer
       # self.conv2 = nn.Conv2d(in_channels=8, out_channels=16, kernel_size=3, padding=1)
       # Fully connected layer
       self.fc1 = nn.Linear( 3380, 64 ) #  self.fc1 = nn.Linear( 64, num_classes) in, out
       self.fc2 = nn.Linear( 64, num_classes )

   def forward(self, x):
       """
       Define the forward pass of the neural network.

       Parameters:
           x: Input tensor.

       Returns:
           torch.Tensor
               The output tensor after passing through the network.
       """
       x = F.relu(self.conv1(x))  # Apply first convolution and ReLU activation
       x = self.norm(x)           # Apply Normalization 
       x = self.pool(x)           # Apply max pooling
#      x = F.utils.parameters_to_vector( x ) 
       x = x.reshape(x.shape[0], -1)  # Flatten the tensor
       x = self.fc1(x)            # Apply fully connected layer
       x = self.fc2(x)            # Apply fully connected layer
       return x




device = "cuda" if torch.cuda.is_available() else "cpu"
print(device)

model = CNN(in_channels=1, num_classes=10).to(device)
#print(model.from(device))






# Define the loss function
criterion = nn.CrossEntropyLoss()

# Define the optimizer
optimizer = optim.Adam(model.parameters(), lr=0.001)


start=time.time()



for epoch in range(num_epochs):
 # Iterate over training batches
   print(f"Epoch [{epoch + 1}/{num_epochs}]")

   for batch_index, (data, targets) in enumerate(tqdm(train_loader)):
       if batch_index>1: 
           continue
       data = data.to(device)
       targets = targets.to(device)
       scores = model(data)
       loss = criterion(scores, targets)
       optimizer.zero_grad()
       loss.backward()
       optimizer.step()


end=time.time()
d=end-start
print("# Python PyTorch 2.0 60000 Images, 500 Epoch Time: " , d)




# Set up of multiclass accuracy metric
acc = Accuracy(task="multiclass",num_classes=10).to(device)

# Iterate over the dataset batches
model.eval()
with torch.no_grad():
   for images, labels in test_loader:
       images=images.to(device)
       labels=labels.to(device)
       # Get predicted probabilities for test data batch
       outputs = model(images)
       _, preds = torch.max(outputs, 1)
       preds = preds.to(device)
       acc(preds, labels)
       #precision(preds, labels)
       #recall(preds, labels)
       

test_accuracy = acc.compute()
print(f"Test accuracy: {test_accuracy}")

clear_session()
