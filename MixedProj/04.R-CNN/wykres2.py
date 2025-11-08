import matplotlib.pyplot as plt
import numpy as np

plt.title('Yolo in Matlab - Team.jpg')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None,None]


d0=[None,None,None,None]
d1=[None,None,None,None]
d2=[None,None,None,None]
d3=[None,None,None,None]
d4=[None,None,None,None]
d5=[None,None,None,None] 

#################################

# net: tiny-yolov2-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :2.230185;
# load image time: 0.083492; detect object time: 1.877422
library[ 3 ]="Yolo2"
d0[3]=2.230185
d1[3]=0.083492
d2[3]=1.877422
# net: tiny-yolov3-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.225820;
# load image time: 0.011383; detect object time: 1.161000
library[ 2 ]="Yolo3"
d0[2]=1.225820
d1[2]=0.011383
d2[2]=1.161000
# net: tiny-yolov4-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :0.718696;
# load image time: 0.011418; detect object time: 0.780485
library[ 1 ]="Yolo4"
d0[1]=0.718696
d1[1]=0.011418
d2[1]=0.780485
# net: tiny-coco; task:dog1; class: dog score: 0.762755;  prepare detectortime: :2.496382;
# load image time: 0.008481; detect object time: 1.285220
library[ 0 ]="YoloX"
d0[0]=2.496382
d1[0]=0.008481
d2[0]=1.285220
 
# --------------------------
 
d3[3]=7.937680 
d4[3]=0.268369 
d5[3]=3.695377 
# net: tiny-yolov3-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.286884; 
# load image time: 0.022838; detect object time: 0.844601 
d3[2]=1.286884 
d4[2]=0.022838 
d5[2]=0.844601 
# net: tiny-yolov4-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.110101; 
# load image time: 0.021239; detect object time: 0.628912 
d3[1]=1.110101 
d4[1]=0.021239 
d5[1]=0.628912 
# net: tiny-coco; task:dog1; class: dog score: 0.763064;  prepare detectortime: :4.376384; 
# load image time: 0.021653; detect object time: 1.316632 
d3[0]=4.376384 
d4[0]=0.021653 
d5[0]=1.316632  
 


################################


# Define library names
#library = ['Yolo2', 'Yolo3', 'Yolo4', 'Yolo5']

# Number of Enthusiasts for different regions
#enthusiasts_north = [2000, 1500, 2500, 2000]
#enthusiasts_south = [1500, 1300, 2000, 1800]
bar_width = 0.25
x = np.arange( len(library) )
off = bar_width

# Grouped Bar Plot
plt.barh( x+3*off  , d0, bar_width, label='przygotowanie detektora GPU', color='r')
plt.barh( x+2*off    , d3, bar_width, label='przygotowanie detektora CPU', color="#AA0000")

plt.barh( x+off    , d1, bar_width, label='wczytanie obrazu GPU', color='g')
plt.barh( x    , d4, bar_width, label='wczytanie obrazu CPU', color="#00AA00")

plt.barh( x-off  , d2, bar_width, label='detekcja GPU', color='b')
plt.barh( x-2*off  , d5, bar_width, label='detekcja CPU', color="#0000AA")

# Adding labels and title
#plt.xlabel('Yolo ')
plt.xlabel('Time[s]')
plt.yticks(x, library)
plt.legend(title='Time[s]')
plt.title('Yolo in Matlab - DOG1.jpg')

plt.savefig( '03_Yolo_MATLAB_dog1.pdf',dpi=400 )
#plt.show()
#plt.close()
 


