
import matplotlib.pyplot as plt
import numpy as np

species = ( "Koszt \nlicencji", "Wygoda \nużytkowania", "Stopień \nwykorzystania \nGPU" )
penguin_means = {
    'Python':  ( 5, 5, 5 ),
    'Matlab':  ( -5, 4, 5 ),
    'C++':     (  5, 3, 5 ),
}

x_ = np.arange(len(species))

width = 0.25
multiplier = .14

plt, ax = plt.subplots(layout='constrained')

for attribute, measurement in penguin_means.items():
    offset = width * multiplier
    rects = ax.bar(x_ + offset, measurement, width, label=attribute)
    ax.bar_label(rects, padding=2)
    ax.color='red';
    multiplier += 1


ax.set_xticks(x_ + width, species)
zz = ax.legend(loc='lower right', ncols=1)


#zz1=zz.legend_handles[1]
#print( zz1 )
#zz1.set_color("yellow")
#ax.legend[0].set_facecolor('yellow')

#ax.legend_handles[1].set_facecolor('yellow')

plt.savefig( '../000.fig/LANG_python.pdf',dpi=400 )
# plt.show()
# plt.close()



