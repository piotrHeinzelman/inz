import matplotlib.pyplot as plt
import numpy as np
plt.title('liczba neuronow / liczba epok,') 
plt.style.use('_mpl-gallery')


x=[10, 10, 10, 10]
p=[None,None,None,None]
pi=[None,None,None,None]
pn=[None,None,None,None]
m=[None,None,None,None]
mi=[None,None,None,None]
j=[None,None,None,None]
jb=[None,None,None,None]
c=[None,None,None,None]

  


p[0]=0.006285429000854492
pi[0]=0.0005295276641845703
m[0]=2305
mi[0]=1998
j[0]=0.00006
c[0]=0.000000542

p[1]=0.006508588790893555
pi[1]=0.0046460628509521484
pn[1]=0.2321
m[1]=2294
mi[1]=1998
j[1]=0.00007
c[1]=0.0000386


p[2]=0.013457536697387695
pi[2]=0.04746580123901367
m[2]=2235
mi[2]=2089
j[2]=0.005
c[2]=0.000377

p[3]= 0.022266149520874023
pi[3]= 0.4420018196105957
m[3]=2164
mi[3]=2089
j[3]=0.007
c[3]=0.003765




plt.plot( x, p,  'bo-', label='Python wbudowany', linewidth=.5 )



plt.legend()
#plt.xscale('log') # 'linear' 'symlog' 'logit' 
#plt.yscale('log') # 'linear' 'symlog' 'logit' 
plt.ylim( 0.1, 5 )
plt.xticks(x,[ '10','10','10','10' ])

  
plt.savefig( '../000.fig/fig030.pdf',dpi=400 ) 
plt.show()
plt.close()



