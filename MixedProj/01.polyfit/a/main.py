import numpy as np
import time 
import datetime

cycles = 1000
name = '4M'

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.double )	
    file.close()
    return data	



x = readBinFile('data/datax'+name+'.bin')
y = readBinFile('data/datay'+name+'.bin')

start = time.time()

for i in range( cycles ):
    a = np.polyfit(x,y,1)

end = time.time()


d = end-start
print ( ' duration:' , d , '[sek.]' )
print ('')
print ( ' X[',x.size,'] * ' , cycles )
print ( ' result: ', a )