from sklearn.datasets import fetch_lfw_people
import matplotlib.pyplot as plt
people = fetch_lfw_people(min_faces_per_person=20, resize=0.8)
# people = fetch_lfw_people( resize=1.0 )

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

