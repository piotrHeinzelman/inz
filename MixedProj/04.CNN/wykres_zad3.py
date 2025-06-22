
import matplotlib.pyplot as plt
import numpy as np

species = ("Matlab", "Python \nPytorch", "Python \nTensorflow", "Java 6243[sek.]")
penguin_means = {
    'CPU': (1103, 649, 732, 0),
    'GPU': (60.9, 640, 182, 0), 
}

x_ = np.arange(len(species))  

width = 0.4  
multiplier = .5

plt, ax = plt.subplots(layout='constrained')

for attribute, measurement in penguin_means.items():
    offset = width * multiplier
    rects = ax.bar(x_ + offset, measurement, width, label=attribute)
    ax.bar_label(rects, padding=2)
    multiplier += 1


 
ax.set_xticks(x_ + width, species)
zz = ax.legend(loc='upper right', ncols=2)
 
plt.savefig( '../000.fig/zad3.pdf',dpi=400 ) 
plt.show()
plt.close()



