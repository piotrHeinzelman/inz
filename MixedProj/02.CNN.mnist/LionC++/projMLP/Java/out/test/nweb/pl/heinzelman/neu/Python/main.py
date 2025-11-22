# https://github.com/TheIndependentCode/Neural-Network/tree/master

import numpy as np
from scipy import signal
#from layer import Layer


ident = [ 0, 1, 0, 0 ]
# ident = np.reshape( (1,3),ident )

x = [0.1,0.2,0.3,0.4]
output_gradient = [ 0.5,0.6,0.7,0.8 ]
# x = np.reshape(x, (3,3) )
print ("X:")
print( x )
print()

_tm  = np.exp( x )
output = _tm / np.sum(_tm)

print( "Output:" )
print( output )
print()


n = np.size( output )
temp = np.reshape(  np.tile( output , n ) , (4,4))
# print("temp:")
# print(temp)

# print ("np.identity(n)  - np.transpose(temp)")
# print ( np.identity(n)  - np.transpose(temp) )

# print ("temp * ( np.identity(n)  - np.transpose(temp))")
# print ( temp * ( np.identity(n)  - np.transpose(temp)) )

ret = np.dot ( temp * ( np.identity(n)  - np.transpose(temp)) , output_gradient )

print ("ret:")
print ( ret )


