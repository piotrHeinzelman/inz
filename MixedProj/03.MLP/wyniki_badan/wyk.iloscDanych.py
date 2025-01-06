import matplotlib.pyplot as plt
import numpy as np
plt.title('zależność dokładności sieci od wielkość zbioru danych uczących') 
plt.style.use('_mpl-gallery')



x = np.array([ 10, 20, 50, 100])
y = np.array([ 82.3, 82.9, 84.74, 88.34  ])
colors = np.array(["blue","blue","blue","blue" ]) 
plt.scatter(x, y, c=colors, label="wielkość zbioru danych uczących")

plt.xlabel('wielkość zbioru [%]')
plt.ylabel('dokładność sieci [%]')

#plt.legend()
plt.savefig( '../000.fig/fig03b.pdf',dpi=400 ) 
plt.show()
plt.close()



