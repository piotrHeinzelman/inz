import matplotlib.pyplot as plt
import numpy as np

plt.title('Trening klasyfikatora Deep CNN 50 epok')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None,None,None]

d0=[None,None,None,None]
d1=[None,None,None,None]
d2=[None,None,None,None,None]
d3=[None,None,None,None,None]
d4=[None,None,None,None,None]
d5=[None,None,None,None]



#################################



### -- TRAIN klasyfikator CNN -- class="SAS" ###
## Epoch:50, GPU:True, loadData:1.317517, createLayers:1.308044, trainTime:315.703167, timeAccuracy:0.931454, accuracy: 1.000000
library[0]="PyTorch + GPU"
d2[0]=14.23
d3[0]=0.13

library[1]="Matlab CUDA"
d2[1]=103.2
d3[1]=3.67


library[2]="TensorFlow"
d2[2]=580
d3[2]=0.4


library[3]="PyTorch bez GPU"
d2[3]=1050
d3[3]=8.2

library[4]="Java"
d2[4]=1135
d3[4]=60



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
plt.savefig( 'trainDeepCNN.pdf',dpi=400 )
#plt.show()
#plt.close()




