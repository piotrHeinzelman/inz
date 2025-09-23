import numpy as np
 
 
 # class torchvision.ops.MLP(in_channels: int, hidden_channels: list[int], norm_layer: ~typing.Optional[~typing.Callable[[...], ~torch.nn.modules.module.Module]] = None, activation_layer: ~typing.Optional[~typing.Callable[[...], ~torch.nn.modules.module.Module]] = <class 'torch.nn.modules.activation.ReLU'>, inplace: ~typing.Optional[bool] = None, bias: bool = True, dropout: float = 0.0)
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
import torch
#from torch import optim
#from torch import nn
#from torch.utils.data import DataLoader
#from tqdm import tqdm

# !pip install torchvision
import torchvision
import torchvision.ops as OP

#import torch.nn.functional as F
#import torchvision.datasets as datasets
#import torchvision.transforms as transforms

# !pip install torchmetrics
#import torchmetrics
#from torchmetrics import Accuracy

 
 
import time

 



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



 
# MLP = OP.MLP(784, [64], activation_layer:'torch.nn.modules.activation.ReLU', bias: bool = True, dropout: float = 0.0) 
model = OP.MLP(784, [64] ) 
 
