
import matplotlib.pyplot as plt
import numpy as np

species = ("Adelie", "Chinstrap", "Gentoo")
penguin_means = {
    'Bill Depth': (18.35, 18.43, 14.98),
    'Bill Length': (38.79, 48.83, 47.50),
    'Flipper Length': (189.95, 195.82, 217.19),
}

x_ = np.arange(len(species))  # the label locations
#x = np.arange(len(species))  # the label locations
x = np.array(['a','b','c'])

width = 0.25  # the width of the bars
multiplier = 0

plt, ax = plt.subplots(layout='constrained')

for attribute, measurement in penguin_means.items():
    offset = width * multiplier
    rects = ax.bar(x_ + offset, measurement, width, label=attribute)
    ax.bar_label(rects, padding=3)
    multiplier += 1

# Add some text for labels, title and custom x-axis tick labels, etc.
#ax.set_ylabel('')
#ax.set_yticks([])


#ax.set_xlabel(['a','b','c'])
#ax.set_x

#ax.set_xticks(['a','b','c'])
#ax.set_xticks(['a','b'])
#ax.set_title('Penguin attributes by species')
ax.set_xticks(x_ + width, species)
ax.legend(loc='upper left', ncols=3)
#ax.set_ylim(0, 250)
 
 
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

 
plt.savefig( '../000.fig/zad2.pdf',dpi=400 ) 
plt.show()
plt.close()



