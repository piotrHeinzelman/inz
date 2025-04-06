# https://github.com/TheIndependentCode/Neural-Network/tree/master

import numpy as np
from scipy import signal
#from layer import Layer





ident = [ 0, 1, 0, 0 ]
# ident = np.reshape( (1,3),ident )


x = [0.1,0.2,0.3,0.4]
output_gradient = [0.5,0.6,0.7,.8]
# x = np.reshape(x, (3,3) )
print ("X:")
print( x )

tmp  = np.exp( x )
output = tmp / np.sum(tmp)

print( "tmp:")
print( tmp )


print("Output:")
print ( output )


n = np.size( output )
print("n:")
print(n)

temp = np.tile( output , n )
print("temp:")
print(temp)

ret = np.dot ( tmp * ( np.identity(n)  - np.transpose(tmp)) , output_gradient )

print ("ret:")
print ( ret )


