import numpy as np
import time 
import datetime

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.double )	
    file.close()
    return data	



x = readBinFile('datax1_double.bin')
y = readBinFile('datay1_double.bin')
print(x)
cycles = 1000

start = time.time()

for i in range( cycles ):
    a = np.polyfit(x,y,1)

end = time.time()

d = end-start
print ( ' duration:' , d , '[sek.]' )
print ('')
print ( ' X[',x.size,'] * ' , cycles )
print ( ' result: ', a )