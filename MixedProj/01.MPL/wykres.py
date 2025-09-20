import matplotlib.pyplot as plt
import numpy as np

plt.title('Trening klasyfikatora MLP 50 epok')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None,None]

d0=[None,None,None,None]
d1=[None,None,None,None]
d2=[None,None,None,None]

#################################


# Matlab, MLP: 2x 64 Neu, epoch=5000, data size=60000, accuracy:0.815000%
library[0]="Matlab GPU\n acc:81.5%"
d0[0]=0.602632
d1[0]=0.323410
d2[0]=217.394381 / 100

#################################

# net: tiny-yolov3-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.225820;
# load image time: 0.011383; detect object time: 1.161000
library[ 1 ]=" ?? "
d0[1]=1.225820
d1[1]=0.011383
d2[1]=1.161000
# net: tiny-yolov4-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :0.718696;
# load image time: 0.011418; detect object time: 0.780485
library[ 2 ]=" ?? "
d0[2]=0.718696
d1[2]=0.011418
d2[2]=0.780485
# net: tiny-coco; task:dog1; class: dog score: 0.762755;  prepare detectortime: :2.496382;
# load image time: 0.008481; detect object time: 1.285220
library[ 3 ]=" ?? "
d0[3]=2.496382
d1[3]=0.008481
d2[3]=1.285220


################################


# Define library names
#library = ['Yolo2', 'Yolo3', 'Yolo4', 'Yolo5']

# Number of Enthusiasts for different regions
#enthusiasts_north = [2000, 1500, 2500, 2000]
#enthusiasts_south = [1500, 1300, 2000, 1800]
bar_width = 0.18
x = np.arange( len(library) )
off = bar_width

# Grouped Bar Plot
plt.bar( x-1.0*off  , d0, bar_width, label='transfer danych do GPU')
plt.bar( x-0.0*off  , d1, bar_width, label='predykcja F')
plt.bar( x+1.0*off  , d2, bar_width, label='trenowanie modelu / 100 F+B')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library) # ,size=5
plt.legend(title='Time[s]')
plt.savefig( 'Pomiary_KlasyfikatorMLP.pdf',dpi=400 )
#plt.show()
#plt.close()




