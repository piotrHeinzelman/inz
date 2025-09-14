import matplotlib.pyplot as plt
import numpy as np

plt.title('Yolo in Matlab')
plt.style.use('_mpl-gallery')


# https://www.mathworks.com/matlabcentral/answers/1755450-how-to-add-numerical-value-in-the-stacked-bar-chart


d1=[None,None,None,None,None,None]
d2=[None,None,None,None,None,None]
d3=[None,None,None,None,None,None]
d4=[None,None,None,None,None,None]
e1=[None,None,None,None,None,None]
e2=[None,None,None,None,None,None]
e3=[None,None,None,None,None,None]
e4=[None,None,None,None,None,None]
f1=[None,None,None,None,None,None]
f2=[None,None,None,None,None,None]
f3=[None,None,None,None,None,None]
f4=[None,None,None,None,None,None]

#################################


################################





# Define library names
library = ['Yolo2', 'Yolo3', 'Yolo4', 'Yolo5']

# Number of Enthusiasts for different regions
enthusiasts_north = [2000, 1500, 2500, 2000]
enthusiasts_south = [1500, 1300, 2000, 1800]
bar_width = 0.28
x = np.arange(len(library))
offset=3*bar_width/3;

# Grouped Bar Plot
plt.bar(x - offset, enthusiasts_north, bar_width, label='load detector time')
plt.bar(x              , enthusiasts_south, bar_width, label='load image time')
plt.bar(x + offset, enthusiasts_south, bar_width, label='detect time')

# Adding labels and title
plt.xlabel('Visualization Library')
plt.ylabel('Number of Enthusiasts')
plt.xticks(x, library)
plt.legend(title='Time[s]')

plt.savefig( '04_RCNN_MAT.pdf',dpi=400 )
plt.show()
plt.close()









#plt.bar(x, d1, 'stacked')


#plt.plot( x, d1,  'bo-', label='task: Dog 1', linewidth=.5 )
#plt.plot( x, d2,  'bo-', label='task: Dog 2', linewidth=.5 )
#plt.plot( x, d3,  'bo-', label='task: Team', linewidth=.5 )
#plt.plot( x, d4,  'bo-', label='pewność wybory klasy', linewidth=.5 )
#plt.plot( x, d5,  'bo-', label='liczba znalezionych obiektów', linewidth=.5 )





#plt.legend()
#plt.xscale('log') # 'linear' 'symlog' 'logit'
#plt.yscale('log') # 'linear' 'symlog' 'logit'
#plt.ylim( 0.1, 5 )
#plt.xticks(x,[ '6','6*10^1','6*10^2','6*10^3','6*10^4','6*10^5','6*10^6','6*10^7'    ])


# plt.savefig( '../000.fig/04_RCNN_MAT.pdf',dpi=400 )
#plt.savefig( '04_RCNN_MAT.pdf',dpi=400 )
#plt.show()
#plt.close()



