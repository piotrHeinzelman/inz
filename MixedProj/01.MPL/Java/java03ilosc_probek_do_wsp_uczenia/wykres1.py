import matplotlib.pyplot as plt
import numpy as np
plt.title('Zależność dokładności uczenia sieci od współczynnika uczenia\n i wielkośc zbioru uczącego') 
plt.style.use('_mpl-gallery')


x=[1,2,3];
y=[1.1,2.2,3.3];
z=[2.2,3.3,4.4];
 

plt.bar3d(x, y, z, label='points in (x, z)')

 


plt.legend()
#plt.xscale('log') # 'linear' 'symlog' 'logit' 
#plt.yscale('log') # 'linear' 'symlog' 'logit' 
#plt.ylim( 0, 1 )
#plt.xticks(x,[ '5','10', '20', '30','50','75', '100', '125'    ])

  
plt.savefig( 'wyk.pdf',dpi=400 ) 
plt.show()
plt.close()



