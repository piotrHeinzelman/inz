import matplotlib.pyplot as plt
import numpy as np



# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

librarye=[None,None,None,None]

e0=[None,None,None,None]
e1=[None,None,None,None]
e2=[None,None,None,None]
e3=[None,None,None,None]
#################################

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

################################



# Define library names
library = ['Yolo2', 'Yolo3', 'Yolo4', 'Yolo5']

# Number of Enthusiasts for different regions
#enthusiasts_north = [2000, 1500, 2500, 2000]
#enthusiasts_south = [1500, 1300, 2000, 1800]
bar_width = 0.28
x = np.arange( len(library) )
offset = bar_width




# Grouped Bar Plot
plt.bar( x-offset         , e0, bar_width, label='przygotowanie detektora')
plt.bar( x         , e1, bar_width, label='wczytanie obrazów z dysku')
plt.bar( x+offset         , e2, bar_width, label='detekcja F')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library, size=5)
plt.legend(title='Time[s]')
plt.title('Yolo in Matlab - Dog2.jpg')
plt.style.use('_mpl-gallery')



plt.savefig( '03_Yolo_MATLAB_dog2.pdf',dpi=400 )
#plt.show()
#plt.close()

