import numpy as np
import time 

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.double )	
    file.close()
    return data	



x = readBinFile('datax1_double.bin')
y = readBinFile('datay1_double.bin')


start = time.time()

for i in range(1000000):
    a = np.polyfit(x,y,1)

end = time.time()

print ('a: ', a )
print ( 'Py duration:' , end-start )