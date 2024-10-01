import numpy as np
import time 

#
def readBinFile( fileName ):
    file = open( fileName, 'rb' )
    data = np.fromfile ( file, dtype=np.uint16 )	
    file.close()
    return data	



x = readBinFile('datax_uint16.bin')
y = readBinFile('datay_uint16.bin')


start = time.time()

for i in range(10000):
    a = np.polyfit(x,y,1)

end = time.time()

print ('a: ', a )
print ( 'Py duration:' , end-start )