import time
import datetime
import sys

cycles = 10
x=2
val=1


start = time.time()
val=val*x
end = time.time()
d = end-start
print ('# value: ', val ,'add in loop: ' , d  , '[sek.]' )

val=1

start = time.time()
for i in range( cycles ):
   val=val*x
end = time.time()
d = end-start
print ('# value: ', val ,'add in loop: ' , d  , '[sek.]' )

val=1

start = time.time()
for i in range( cycles ):
   for j in range( cycles ):
      val=val*2
end = time.time()
d = end-start
print ('# value: ', val ,'add in loop: ' , d  , '[sek.]' )

