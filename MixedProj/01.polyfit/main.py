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

for c in range( cycles ):
    a = np.polyfit(x,y,1)

end = time.time()


d = end-start

print ('# polyfit() X[',x.size,'] * ' , cycles ,' result: ', a )
print ('# time: ' , d  , '[sek.]' )
print ('')
print ('y[0]=' , d )
print ('')











start = time.time()

for c in range( cycles ):
    xsr=0
    ysr=0
    for i in range( len(x) ):
        xsr+=x[i]
        ysr+=y[i]          
    xsr=xsr/len(x)
    ysr=ysr/len(x)

    w0=0
    w1=0
    sumTop=0
    sumBottom=0
    for i in range( len(x) ):
        sumTop   +=(x[i]-xsr)*(y[i]-ysr)
        sumBottom+=(x[i]-xsr)*(x[i]-xsr)

    w1=sumTop/sumBottom
    w0=ysr - w1*xsr

end = time.time()
d = end-start


print ('# implementation X[',x.size,'] * ' , cycles ,' w0: ', w0 , ', w1: ' , w1  )
print ('# time: ' , d  , '[sek.]' )
print ('')
print ('y[1]=' , d )
print ('')
