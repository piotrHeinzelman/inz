import matplotlib.pyplot as plt
import numpy as np
plt.title('Czas [s] : CNN klasyfikacja cyfr - MNIST : 5x5 * 20 Filter 500 epoch') 
plt.style.use('_mpl-gallery')



#    Matlab Matlab  GPU

#x = np.array([1,2,3,4,           10,11,12,13,       20,21,      30,31,32,33            ])
#y = np.array([211,206,205,205,   419,425,419,422,   1998, 2089, 2305,2294,2235,2164    ])
#colors = np.array(["red","red","red","red", "orange","orange","orange","orange", "red","red", "orange","orange","orange","orange" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors)

x = np.array([ 3, 3, 4, 5, 6         ])
y = np.array([ 0, 791, 801, 788, 788 ])
colors = np.array(["white","blue","blue","blue","blue" ]) # "red"
plt.scatter(x, y, c=colors, label="Matlab - GPU   791 [sek.]")


#x = np.array([8,9,10,11      ])
#y = np.array([419,425,419,422  ])
#colors = np.array(["cyan","cyan","cyan","cyan" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors, label="Matlab window10 GPU     422[sek.]")




#x = np.array([19,20 ])
#y = np.array([1998, 2089 ])
#colors = np.array(["red","red" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors, label="Matlab Arch Linux      2044[sek.]")


#x = np.array([23,24,25,26            ])
#y = np.array([2305,2294,2235,2164    ])
#colors = np.array(["magenta","magenta","magenta","magenta" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors, label="Matlab window 10      2250[sek.]")




#x = np.array([13,14,15  ])
#y = np.array([83.58, 83.69, 83.23  ])
#colors = np.array(["green" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors, label="Python sklearn - GPU 83.58 [sek.]")


plt.legend()
plt.savefig( '../000.fig/fig04.pdf',dpi=400 )
plt.show()
plt.close()



