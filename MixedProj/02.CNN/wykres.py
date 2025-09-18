import matplotlib.pyplot as plt
import numpy as np

plt.title('Trening klasyfikatora CNN w Matlab, 50 epok')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None,None]

d0=[None,None,None,None]
d1=[None,None,None,None]
d2=[None,None,None,None]
d3=[None,None,None,None]



#################################


## Epoch:50, GPU:Yes, loadData:1.378996, createLayers:1.355974, trainTime:326.833199, timeAccuracy:0.941128, accuracy: 1.000000

library[0]="Matlab GPU"
d0[0]=1.378996
d1[0]=1.355974
d2[0]=326.833199/50
d3[0]=0.941128

#################################

# net: tiny-yolov3-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.225820;
# load image time: 0.011383; detect object time: 1.161000
library[ 1 ]=" ?? "
d0[1]=1.225820
d1[1]=0.011383
d2[1]=1.161000
d3[1]=1.161000
# net: tiny-yolov4-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :0.718696;
# load image time: 0.011418; detect object time: 0.780485
library[ 2 ]=" ?? "
d0[2]=0.718696
d1[2]=0.011418
d2[2]=0.780485
d3[2]=0.780485
# net: tiny-coco; task:dog1; class: dog score: 0.762755;  prepare detectortime: :2.496382;
# load image time: 0.008481; detect object time: 1.285220
library[ 3 ]=" ?? "
d0[3]=2.496382
d1[3]=0.008481
d2[3]=1.285220
d3[3]=1.285220


################################


# Define library names
#library = ['Yolo2', 'Yolo3', 'Yolo4', 'Yolo5']

# Number of Enthusiasts for different regions
#enthusiasts_north = [2000, 1500, 2500, 2000]
#enthusiasts_south = [1500, 1300, 2000, 1800]
bar_width = 0.18
x = np.arange( len(library) )
offset = bar_width

# Grouped Bar Plot
plt.bar( x-offset         , d0, bar_width, label='load image')
plt.bar( x         , d1, bar_width, label='create layers')
plt.bar( x+offset         , d2, bar_width, label='training time 1 epoch')
plt.bar( x+offset+offset  , d3, bar_width, label='prediction time')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library) # ,size=5
plt.legend(title='Time[s]')
plt.title('CNN trening klasyfikatora Matlab.jpg')

plt.savefig( '02_CNN_MAT.pdf',dpi=400 )
#plt.show()
#plt.close()




