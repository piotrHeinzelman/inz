import numpy as np
import time
import datetime

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.uint16 )
    file.close()
    return data

x = readBinFile('datax_uint16.bin')
y = readBinFile('datay_uint16.bin')
cycles = 987

start = time.time()

for i in range( cycles ):
    a = np.polyfit(x,y,1)

end = time.time()

d = end-start
print ( ' duration:' , d , '[sek.]' )
print ('')
print ( ' X[',x.size,'] * ' , cycles )
print ( ' result: ', a )