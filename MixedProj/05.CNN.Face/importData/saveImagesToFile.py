from sklearn.datasets import fetch_lfw_people
import matplotlib.pyplot as plt

# 1	Jennifer_Aniston
# 2	Jennifer_Capriati
# 3	Jennifer_Lopez
# 4	Laura_Bush
# 5	Lindsay_Davenport
# 6	Megawati_Sukarnoputri
# 7	Naomi_Watts
# 8	Angelina_Jolie
# 9	Serena_Williams
# 10 Winona_Ryder


fileX=open( 'trainX', 'wb' )
fileY=open( 'trainY', 'wb' )

for ( j ) in range (1,16): # 21 # 16
    for ( i ) in range(1,11): # 10
        # name = 'data/'+str( i )+'_'+str( j )+'.png'
        name = 'data/JPEG/'+str( i )+'_'+str( j )+'.jpg'
        img = plt.imread( name )
        img = img.reshape(75*100*3) # 75 * 100 * 4 # 22500
        img = img /255
        #print( name )
        #print( img.shape )
        #print( img )
        fileX.write( img )
        fileY.write ( i.to_bytes(1, 'big') )
fileX.close()
fileY.close()

fileX=open( 'testX', 'wb' )
fileY=open( 'testY', 'wb' )

for ( j ) in range (16,21): # 21 # 16
    for ( i ) in range(1,11): # 10
        # name = 'data/'+str( i )+'_'+str( j )+'.png'
        name = 'data/JPEG/'+str( i )+'_'+str( j )+'.jpg'
        img = plt.imread( name )
        img = img.reshape(75*100*3) # 75 * 100 * 4 # 22500
        img = img /255
        #print( name )
        #print( img.shape )
        #print( img )
        fileX.write( img )
        fileY.write ( i.to_bytes(1, 'big') )
fileX.close()
fileY.close()


 
