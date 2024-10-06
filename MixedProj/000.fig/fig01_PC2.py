import matplotlib.pyplot as plt 
import numpy as np
plt.title('Regresja liniowa: ThPad Intel 4xi5 3320  ') 
plt.style.use('_mpl-gallery')


x=[6,60,600,6000,60000,600000,6000000,60000000]
p=[None,None,None,None,None,None,None,None]
pi=[None,None,None,None,None,None,None,None]
m=[None,None,None,None,None,None,None,None]
mi=[None,None,None,None,None,None,None,None]
j=[None,None,None,None,None,None,None,None]

  

p[0]= 0.007216453552246094
pi[0]= 0.0009086132049560547
m[0]=0.285766
mi[0]=0.004392
j[0]=0.008

p[1]= 0.007467746734619141
pi[1]= 0.007461071014404297
m[1]=0.285728
mi[1]=0.005407
j[1]=0.011

p[2]= 0.011977672576904297
pi[2]= 0.08527302742004395
m[2]=0.296246
mi[2]=0.006690
j[2]=0.031

p[3]= 0.053145647048950195
pi[3]= 0.8866162300109863
m[3]=0.292239
mi[3]=0.024420
j[3]=0.142

p[4]= 0.5393099784851074
pi[4]= 8.356201648712158
m[4]=0.381668
mi[4]=0.058863
j[4]=1.304

p[5]= 5.178142547607422
pi[5]= 80.40761542320251
m[5]=2.755219
mi[5]=0.423003
j[5]=15.816

p[6]= 55.40460753440857
pi[6]= 886.1782727241516
m[6]=27.076191
mi[6]=4.269571
j[6]=239.418





plt.plot( x, p, 'b.-', label='Python wbudowany', linewidth=.5 )
plt.plot( x, pi, 'b.:', label='Python wlasna impl.', linewidth=.5 )
plt.plot( x, m, 'r.-', label='Matlab wbudowany', linewidth=.5 )
plt.plot( x, mi, 'r.:', label='Matlab wlasna impl', linewidth=.5 )
plt.plot( x, j, 'g.-', label='Java', linewidth=.5 )



plt.legend()
plt.xscale('log') # 'linear' 'symlog' 'logit' 
plt.yscale('log') # 'linear' 'symlog' 'logit' 
#plt.ylim( 0.1, 5 )
plt.xticks(x,[ '6','6*10^1','6*10^2','6*10^3','6*10^4','6*10^5','6*10^6','6*10^7' ])
plt.xlabel('wielkosc wektora')

plt.savefig( '../000.fig/fig01_PC2.pdf',dpi=400 ) 
plt.show()
plt.close()


