import matplotlib.pyplot as plt
import numpy as np

plt.style.use('_mpl-gallery')

# make data
x = np.arange(20, 65535)
my = [ 0.11     , 0.57   ]
py = [ 0.036    , 3.16 ]
jy = [ 0.003    , 0.111  ]
cy = [ 0.000136 , 0.41   ]
y = np.vstack([my, py, jy, cy])

# plot
fig, ax = plt.subplots()

ax.stackplot(x, y)

ax.set(xlim=(0, 8), xticks=np.arange(1, 8),
       ylim=(0, 8), yticks=np.arange(1, 8))

plt.show()