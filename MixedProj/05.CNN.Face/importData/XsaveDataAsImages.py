from sklearn.datasets import fetch_lfw_people
import matplotlib.pyplot as plt
people = fetch_lfw_people(min_faces_per_person=20, resize=0.8)
# people = fetch_lfw_people( resize=1.0 )

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




for ( i ) in range ( 9999999999 ):
   # print( i )
   my_str = './data/'+str(people.target[i])+'_'+ people.target_names[ people.target[i]] +'_'+str(i)+'.png'
   #print ( my_str )
   plt.imsave( my_str , people.images[i] )


   # print( people.images[i].shape )
   # print( people.images[i] )
   # print ( people.target_names[i] )

   #print( person.target_names )
   #print( person )


#for name in people.target_names:
#    print(name)

#lfw_people.data.dtype

#lfw_people.data.shape

#lfw_people.images.shape

