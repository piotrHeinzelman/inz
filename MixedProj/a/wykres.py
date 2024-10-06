import matplotlib.pyplot as plt 
import numpy as np
plt.title('Regresja liniowa: polyfit  X[6] x 100') 
plt.style.use('_mpl-gallery')


x=[6,60,600,6_000,60_000,600_000,6_000_000,60_000_000]
p=[None,None,None,None,None,None,None,None]
pi=[None,None,None,None,None,None,None,None]
m=[None,None,None,None,None,None,None,None]
mi=[None,None,None,None,None,None,None,None]
j=[None,None,None,None,None,None,None,None]
jb=[None,None,None,None,None,None,None,None]
c=[None,None,None,None,None,None,None,None]


#p[0]=0.12
#p[1]=1.2
#p[2]=3

#m[0]=0.3
#m[1]=0.4
#m[2]=0.5


plt.plot( x, p, '.-', label='Python', linewidth=.5 )
plt.plot( x, p, '.-', label='Python', linewidth=.5 )
plt.plot( x, m, '.-', label='Matlab', linewidth=.5 )
plt.plot( x, m, '.-', label='Matlab', linewidth=.5 )



plt.legend()
plt.xscale('log') # 'linear' 'symlog' 'logit' 
plt.yscale('log') # 'linear' 'symlog' 'logit' 
plt.ylim( 0.1, 5 )
plt.xticks(x,[ '6','6*10^1','6*10^2','6*10^3','6*10^4','6*10^5','6*10^6','6*10^7'    ])





  
  
plt.savefig( '../000.fig/fig01a.pdf',dpi=400 ) 
plt.show()
plt.close()
