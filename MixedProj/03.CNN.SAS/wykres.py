import matplotlib.pyplot as plt
import numpy as np

plt.title('Trening klasyfikatora CNN 50 epok')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None]

d0=[None,None,None]
d1=[None,None,None]
d2=[None,None,None]
d3=[None,None,None]
d4=[None,None,None]
d5=[None,None,None]



#################################



### -- TRAIN klasyfikator CNN -- class="SAS" ###
## Epoch:50, GPU:True, loadData:1.317517, createLayers:1.308044, trainTime:315.703167, timeAccuracy:0.931454, accuracy: 1.000000
library[0]="Matlab GPU"
#d0[0]=1.317517
#d1[0]=1.308044
d2[0]=95.21/50
d3[0]=3.4
#d4[0]=0.097898
#d5[0]=16.519


## ##

library[1]="Python\n PyTorch GPU (33%)"
#d0[2]=0
#d1[2]=0
d2[1]=14.23/50
d3[1]=0.13
#d4[2]=0
#d5[2]=0
# ##

library[2]="C++ GPU"
#d0[3]=d0[0]*0.0
#d1[3]=d1[0]*0.0
d2[2]=d2[0]*0.0
d3[2]=d3[0]*0.0
#d4[3]=d4[0]*0.0
#d5[3]=d5[0]*0.0

# prepare detector : 0.097898
# train detector   : 16.519395
# epoch: 100
# images: 10


#################################


bar_width = 0.12
x = np.arange( len(library) )
off = bar_width

# Grouped Bar Plot
#plt.bar( x-2.5*off  , d0, bar_width, label='wczytanie danych uczących CNN')
#plt.bar( x-1.5*off  , d1, bar_width, label='budowanie modelu CNN')
plt.bar( x-0.5*off  , d2, bar_width, label='trening')
plt.bar( x+0.5*off  , d3, bar_width, label='predykcja')
#plt.bar( x+1.5*off  , d4, bar_width, label='budowanie detektora Yolo4')
#plt.bar( x+2.5*off  , d5, bar_width, label='uczenie detektora Yolo4')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library) # ,size=5
plt.legend(title='Time[s]')
plt.savefig( 'Pomiary_KlasyfikatorCNN.pdf',dpi=400 )
#plt.show()
#plt.close()




