import matplotlib.pyplot as plt
import numpy as np

plt.title('Yolo w językach')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None,None,None,None]
librarye=[None,None,None,None,None,None]
libraryf=[None,None,None,None]


d0=[None,None,None,None]
d1=[None,None,None,None]
d2=[None,None,None,None]
d3=[None,None,None,None]

e0=[None,None,None,None,None,None]
e1=[None,None,None,None,None,None]
e2=[None,None,None,None,None,None]
e3=[None,None,None,None,None,None]

f0=[None,None,None,None]
f1=[None,None,None,None]
f2=[None,None,None,None]
f3=[None,None,None,None]

#################################
"""
# net: tiny-yolov2-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :2.230185;
# load image time: 0.083492; detect object time: 1.877422
library[ 0 ]=" tiny-yolov2-coco\n score:0, find(0) "
d0[0]=2.230185
d1[0]=0.083492
d2[0]=1.877422
# net: tiny-yolov3-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.225820;
# load image time: 0.011383; detect object time: 1.161000
library[ 1 ]=" tiny-yolov3-coco\n score:0 find(0) "
d0[1]=1.225820
d1[1]=0.011383
d2[1]=1.161000
# net: tiny-yolov4-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :0.718696;
# load image time: 0.011418; detect object time: 0.780485
library[ 2 ]=" tiny-yolov4-coco\n score:0 find(0) "
d0[2]=0.718696
d1[2]=0.011418
d2[2]=0.780485
# net: tiny-coco; task:dog1; class: dog score: 0.762755;  prepare detectortime: :2.496382;
# load image time: 0.008481; detect object time: 1.285220
library[ 3 ]=" tiny-coco\n score:0.76 find(1) "
d0[3]=2.496382
d1[3]=0.008481
d2[3]=1.285220
"""
# net: tiny-yolov2-coco; task:dog2; class: dog score: 0.879725;  prepare detectortime: :0.523928;
# load image time: 0.020516; detect object time: 0.320706
librarye[ 0 ]=" tiny-yolov2-coco\n score:0.87 find(1) "
e0[0]=0.523928
e1[0]=0.020516
e2[0]=0.320706
# net: tiny-yolov3-coco; task:dog2; class: dog score: 0.936445;  prepare detectortime: :0.404241;
# load image time: 0.007615; detect object time: 0.318037
librarye[ 1 ]=" tiny-yolov3-coco\n score:0.93 find(1)"
e0[1]=0.404241
e1[1]=0.007615
e2[1]=0.318037
# net: tiny-yolov4-coco; task:dog2; class: dog score: 0.588947;  prepare detectortime: :0.371717;
# load image time: 0.005622; detect object time: 0.299549
librarye[ 2 ]=" tiny-yolov4-coco\n score:0.58 find(1)"
e0[2]=0.371717
e1[2]=0.005622
e2[2]=0.299549
# net: tiny-coco; task:dog2; class: dog score: 0.922000;  prepare detectortime: :1.426154;
# load image time: 0.005423; detect object time: 0.646664
librarye[ 3 ]=" tiny-coco\n score:0.92 find(1)"
e0[3]=1.426154
e1[3]=0.005423
e2[3]=0.646664

librarye[ 4 ]="Python\nYolo8"
e0[4]=0.045
e1[4]=0
e2[4]=0.445

librarye[ 5 ]="C++ \nTorch"
e0[5]=0.00
e1[5]=0
e2[5]=0.399



"""
# net: tiny-yolov2-coco; task:team; class: person score: 0.707635;  prepare detectortime: :0.340283; 
# load image time: 0.053012; detect object time: 0.186609 
libraryf[ 0 ]=" tiny-yolov2-coco\n score:0.70 find(6)"
f0[0]=0.340283 
f1[0]=0.053012 
f2[0]=0.186609 
# net: tiny-yolov3-coco; task:team; class: person score: 0.949395;  prepare detectortime: :0.301683; 
# load image time: 0.016144; detect object time: 0.165678
libraryf[ 1 ]=" tiny-yolov3-coco\n score:0.94 find(9) "
f0[1]=0.301683 
f1[1]=0.016144 
f2[1]=0.165678 
# net: tiny-yolov4-coco; task:team; class: person score: 0.718039;  prepare detectortime: :0.345861; 
# load image time: 0.011555; detect object time: 0.260877
libraryf[ 2 ]=" tiny-yolov4-coco\n score:0.71 find(6)"
f0[2]=0.345861 
f1[2]=0.011555 
f2[2]=0.260877 
# net: tiny-coco; task:team; class: person score: 0.878444;  prepare detectortime: :1.249539; 
# load image time: 0.007218; detect object time: 0.594101 
libraryf[ 3 ]=" tiny-coco\n score:0.87 find(7)" 
f0[3]=1.249539 
f1[3]=0.007218 
f2[3]=0.594101 
"""

################################



# Define library names
#library = ['Yolo2', 'Yolo3', 'Yolo4', 'Yolo5']

# Number of Enthusiasts for different regions
#enthusiasts_north = [2000, 1500, 2500, 2000]
#enthusiasts_south = [1500, 1300, 2000, 1800]
bar_width = 0.45
x = np.arange( len(library) )
offset = bar_width
"""
# Grouped Bar Plot
plt.bar( x-offset         , d0, bar_width, label='przygotowanie detektora')
plt.bar( x         , d1, bar_width, label='wczytanie obrazów z dysku')
plt.bar( x+offset         , d2, bar_width, label='detekcja F')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library, size=5)
plt.legend(title='Time[s]')
plt.title('Yolo in Matlab - Dog1.jpg')

plt.savefig( '03_Yolo_MATLAB_dog1.pdf',dpi=400 )
#plt.show()
#plt.close()
"""

######################################

library = ['Matlab\nYolo2', 'Matlab\nYolo3', 'Matlab\nYolo4', 'Matlab\nYolo5', 'Python\nYolo3','C++ Torch\nYolo 8']

#plt.style.use('_mpl-gallery')

# Grouped Bar Plot
#plt.bar( x-0.5*offset         , e0, bar_width, label='przygotowanie detektora')
#plt.bar( x                , e1, bar_width, label='wczytanie obrazów z dysku')
plt.bar( x+0.1*offset         , e2, bar_width, label='detekcja')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library, size=5)
plt.legend(title='Time[s]')
#plt.title('Yolo in Matlab - Dog2.jpg')

plt.savefig( 'yoloForwadrTime.pdf',dpi=400 )
#plt.show()
#plt.close()


#########################################

"""
plt.title('Yolo in Matlab - Team.jpg')
plt.style.use('_mpl-gallery')

# Grouped Bar Plot
plt.bar( x-offset         , f0, bar_width, label='przygotowanie detektora')
plt.bar( x         , f1, bar_width, label='wczytanie obrazów z dysku')
plt.bar( x+offset         , f2, bar_width, label='detekcja F')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library)
plt.legend(title='Time[s]')
plt.title('Yolo in Matlab - Team.jpg')

plt.savefig( '03_Yolo_MATLAB_team.pdf',dpi=400 )
#plt.show()
#plt.close()
"""






