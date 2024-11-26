import numpy as np
import time 
import datetime
import sys

#import numba
from numba import jit, prange, uint8, float32, float32

cycles = 100
name = '4M'


@jit( nopython=True  ) # nopython=True, parallel=True
def myCalc():
    Len = len(x)
    w0=0
    w1=0
    for c in range( cycles ):
        xsr=0
        ysr=0
        for i in range( Len ):
            xsr+=x[i]
            ysr+=y[i]

        xsr=xsr/Len
        ysr=ysr/Len

        w0=0
        w1=0
        sumTop=0
        sumBottom=0

        for i in range( Len ):
            z=(x[i]-xsr)
            sumTop+=(z*(y[i]-ysr))
            sumBottom+=(z*z)

        w1=sumTop/sumBottom
        w0=ysr-(w1*xsr)
    return ( w0, w1 )



def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.double )	
    file.close()
    return data	
    


x = readBinFile('data/datax'+name+'.bin')
y = readBinFile('data/datay'+name+'.bin')


start = time.time()

(w0,w1) = myCalc()

end = time.time()
d = end-start


print ('# implementation X[',x.size,'] * ' , cycles ,' w1: ', w1 , ', w0: ' , w0  )
print ('# time: ' , d  , '[sek.]' )
print ('')
print ('pnumba[]=' , d )
print ('')



