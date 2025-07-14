
import matplotlib.pyplot as plt
import numpy as np

species = ("Matlab", "Python \nScikit", "Python \nTensorflow", "Java")
penguin_means = {
    'CPU': (28.3, 14.08, 69, 127),
    'GPU': (14.6, 13.79, 88, 127), 
}

x_ = np.arange(len(species))  
x = np.array(['a','b','c'])

width = 0.4  
multiplier = .5

plt, ax = plt.subplots(layout='constrained')

for attribute, measurement in penguin_means.items():
    offset = width * multiplier
    rects = ax.bar(x_ + offset, measurement, width, label=attribute)
    ax.bar_label(rects, padding=2)
    ax.color='red';
    multiplier += 1


 
ax.set_xticks(x_ + width, species)
zz = ax.legend(loc='upper left', ncols=2)


#zz1=zz.legend_handles[1]
#print( zz1 )
#zz1.set_color("yellow")
#ax.legend[0].set_facecolor('yellow')

#ax.legend_handles[1].set_facecolor('yellow')
 
plt.show()









# xticklabels({'Python Scikit','Python','Python Tensorflow','Java'})

#x = np.array([ 1, 2, ])
#y = np.array([ 14.08, 13.79 ])
#colors = np.array(["blue","cyan" ]) # "red"
#plt.scatter(x, y, c=colors, label="Matlab - GPU   15.56 [sek.]")


 




        #x = np.array([1,2,3,4,           10,11,12,13,       20,21,      30,31,32,33            ])
        #y = np.array([211,206,205,205,   419,425,419,422,   1998, 2089, 2305,2294,2235,2164    ])
        #colors = np.array(["red","red","red","red", "orange","orange","orange","orange", "red","red", "orange","orange","orange","orange" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
 
#x = np.array([13,14,15  ])
#y = np.array([83.58, 83.69, 83.23  ])
#colors = np.array(["green" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors, label="Python sklearn - GPU 83.58 [sek.]")


#x = np.array([ 23, 24, 25  ])
#y = np.array([ 482.10 , 483.86, 481.90 ])
#colors = np.array(["brown" ]) #"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])
#plt.scatter(x, y, c=colors, label="Python TensorFlow - GPU 481 [sek.]")



#plt.scatter(x, y, c=colors, label="Java 14426 [sek.]")

 
plt.savefig( '../000.fig/zad_MLP.pdf',dpi=400 ) 
plt.show()
plt.close()



