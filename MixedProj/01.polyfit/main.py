
from numba import jit, cuda

import numpy as np
import time
import datetime

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.uint16 )
    file.close()
    return data

@jit(target_backend='cuda')
def calc( cycles, x,y):
    for i in range(cycles):
        a = np.polyfit(x, y, 1)
        return a

x = readBinFile('datax_uint16.bin')
y = readBinFile('datay_uint16.bin')
cycles = 1000
a = calc(cycles, x, y)

start = time.time()




end = time.time()

d = end-start
print ( ' duration:' , d , '[sek.]' )
print ('')
print ( ' X[',x.size,'] * ' , cycles )
print ( ' result: ', a )