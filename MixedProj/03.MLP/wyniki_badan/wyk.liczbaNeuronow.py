import matplotlib.pyplot as plt
import numpy as np
plt.title('dokładność sieci / ilość neuronow') 
plt.style.use('_mpl-gallery')


x = np.array([12, 16, 32, 64, 128      ])
y = np.array([77.93, 71.04, 87.6, 88.34 , 87.54  ])
colors = np.array(["blue","blue","blue","blue","blue" ]) 
plt.scatter(x, y, c=colors, label="zaleznosc od ilosci neuronow")

plt.xlabel('liczba neuronów w warstwie')
plt.ylabel('dokładność sieci[%]');

#plt.legend()
plt.savefig( '../000.fig/fig03a.pdf',dpi=400 ) 
plt.show()
plt.close()



