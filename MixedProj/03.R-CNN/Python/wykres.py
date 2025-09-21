import matplotlib.pyplot as plt
import numpy as np

plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart
# https://www.datacamp.com/tutorial/python-bar-plot

library=[None,None,None]
d0=[None,None,None]
d1=[None,None,None]
d2=[None,None,None]

#################################

# net: tiny-yolov2-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :2.230185;
# load image time: 0.083492; detect object time: 1.877422
library[ 0 ]="Yolo3 DOG\n find(1) "
d0[0]=0.04591965675354004
d1[0]=56.78736448287964
d2[0]=0.4355125427246094


# Create Model:
# Training Model:
# Detect time:

# net: tiny-yolov3-coco; task:team; class: person score: 0.949395;  prepare detectortime: :0.301683;
# load image time: 0.016144; detect object time: 0.165678
library[ 1 ]="Yolo3 DOG2\n find(1)"
d0[1]=0.043099164962768555
d1[1]=0.016144
d2[1]=1.0444037914276123
# Create Model:
# Detect time:
# net: tiny-yolov4-coco; task:team; class: person score: 0.718039;  prepare detectortime: :0.345861;
# load image time: 0.011555; detect object time: 0.260877
library[ 2 ]="Yolo3 TEAM\n find(7)"
d0[2]=0.07130837440490723
d1[2]=0.016144
d2[2]=1.0438988208770752
 # Create Model:
# Detect time:


bar_width = 0.28
x = np.arange( len(library) )
offset = bar_width/2

plt.style.use('_mpl-gallery')


# Grouped Bar Plot
plt.bar( x-offset         , d0, bar_width, label='przygotowanie detektora')
#plt.bar( x         , d1, bar_width, label='wczytanie obrazów z dysku')
plt.bar( x+offset         , d2, bar_width, label='detekcja F')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library)
plt.legend(title='Time[s]')
plt.title('Yolo in Python')

plt.savefig( '03_Yolo_Python.pdf',dpi=400 )
#plt.show()
#plt.close()
