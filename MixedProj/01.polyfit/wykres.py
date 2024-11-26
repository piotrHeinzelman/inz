import matplotlib.pyplot as plt
import numpy as np
plt.title('Regresja liniowa: polyfit  X[6] x 100') 
plt.style.use('_mpl-gallery')


x=[6,60,600,6_000,60_000,600_000,6_000_000,60_000_000]
p=[None,None,None,None,None,None,None,None]
pi=[None,None,None,None,None,None,None,None]
pn=[None,None,None,None,None,None,None,None]
m=[None,None,None,None,None,None,None,None]
mi=[None,None,None,None,None,None,None,None]
j=[None,None,None,None,None,None,None,None]
jb=[None,None,None,None,None,None,None,None]
c=[None,None,None,None,None,None,None,None]

  


p[0]=0.006285429000854492
pi[0]=0.0005295276641845703
m[0]=0.116236
mi[0]=0.002762
j[0]=0.00006
c[0]=0.000000542

p[1]=0.006508588790893555
pi[1]=0.0046460628509521484
pn[1]=0.2321
m[1]=0.119444
mi[1]=0.002877
j[1]=0.00007
c[1]=0.0000386


p[2]=0.013457536697387695
pi[2]=0.04746580123901367
m[2]=0.113454
mi[2]=0.003579
j[2]=0.005
c[2]=0.000377

p[3]= 0.022266149520874023
pi[3]= 0.4420018196105957
m[3]=0.105964
mi[3]=0.010766
j[3]=0.007
c[3]=0.003765

p[4]= 0.3423604965209961
pi[4]= 4.443346738815308
m[4]=0.141357
mi[4]=0.029239
j[4]=0.017
c[4]=0.037662

p[5]= 2.708757162094116
pi[5]= 45.06006598472595
pn[5]= 0.9
m[5]=1.461024
mi[5]=0.204299
j[5]=0.102

p[6]= 31.923200130462646
pi[6]=459.18202471733093
m[6]=14.773479
mi[6]=1.915774
j[6]=1.029

p[7]= 297.654235124588
m[7]=140.964373
mi[7]=18.935610
j[7]=10.143





plt.plot( x, p,  'bo-', label='Python wbudowany', linewidth=.5 )
plt.plot( x, pi, 'bo:', label='Python wlasna impl.', linewidth=.5 )
plt.plot( x, pn, 'yo:', label='Python numba wlasna impl.', linewidth=.5 )
plt.plot( x, m,  'ro-', label='Matlab wbudowany', linewidth=.5 )
plt.plot( x, mi, 'ro:', label='Matlab wlasna impl', linewidth=.5 )
plt.plot( x, j,  'go-', label='Java', linewidth=.5 )
plt.plot( x, c,  'yo-', label='C', linewidth=.5 )



plt.legend()
plt.xscale('log') # 'linear' 'symlog' 'logit' 
plt.yscale('log') # 'linear' 'symlog' 'logit' 
plt.ylim( 0.1, 5 )
plt.xticks(x,[ '6','6*10^1','6*10^2','6*10^3','6*10^4','6*10^5','6*10^6','6*10^7'    ])

  
plt.savefig( '../000.fig/fig01.pdf',dpi=400 ) 
plt.show()
plt.close()



