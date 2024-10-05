import numpy as np
import time 
import datetime

cycles = 1000
name = '20'

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

print ('#  X[',x.size,'] * ' , cycles ,' result: ', a )
print ('# time: ' , d  , '[sek.]' )
print ('')

print ('   y[0]=' , d )

print ('')


