import matplotlib.pyplot as plt
import numpy as np



# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

libraryf=[None,None,None,None]

f0=[None,None,None,None]
f1=[None,None,None,None]
f2=[None,None,None,None]
f3=[None,None,None,None]

#################################
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
plt.bar( x-offset         , f0, bar_width, label='przygotowanie detektora')
plt.bar( x         , f1, bar_width, label='wczytanie obrazów z dysku')
plt.bar( x+offset         , f2, bar_width, label='detekcja F')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library, size=5)
plt.legend(title='Time[s]')
plt.title('Yolo in Matlab - Team.jpg')
plt.style.use('_mpl-gallery')



plt.savefig( '03_Yolo_MATLAB_team.pdf',dpi=400 )
#plt.show()
#plt.close()







