import numba
from numba import jit, cuda
print(cuda.gpus)

numba.cuda.select_device( 0 )




import numpy as np
import time 
import datetime

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.double )	
    file.close()
    return data


#@jit(target_backend='cuda')
#@jit(target_backend='cuda')
#@jit
@cuda.jit(device=True)
#@numba.jit(target='cuda') 
def calc(x,y):
    a=np.polyfit(x,y,1)
    return a


x = readBinFile('datax1_double.bin')
y = readBinFile('datay1_double.bin')
cycles = 987

start = time.time()

for i in range( cycles ):
    a = calc( x,y )


end = time.time()

d = end-start
print ( ' duration:' , d , '[sek.]' )
print ('')
print ( ' X[',x.size,'] * ' , cycles )
print ( ' result: ', a )