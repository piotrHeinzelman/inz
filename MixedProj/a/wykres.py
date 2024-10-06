import matplotlib.pyplot as plt 
import numpy as np
plt.title('Regresja liniowa: polyfit  X[6] x 100') 
plt.style.use('_mpl-gallery')


x=[6,60,600,6_000,60_000,600_000,6_000_000,60_000_000]
p=[None,None,None,None,None,None,None,None]
m=[None,None,None,None,None,None,None,None]


x[0]=60
x[1]=600
x[2]=6000

p[0]=0.12
p[1]=1.2
p[2]=3

m[0]=0.3
m[1]=0.4
m[2]=0.5


plt.plot( x, p, 'x-', label='Python', linewidth=2 )
plt.plot( x, m, 'o-', label='Matlab', linewidth=2 )
plt.legend()
plt.xscale('log') # 'linear' 'symlog' 'logit' 
plt.yscale('log') # 'linear' 'symlog' 'logit' 
plt.ylim( 0.1, 5 )
plt.xticks(x,[ '6','6*10^1','6*10^2','6*10^3','6*10^4','6*10^5','6*10^6','6*10^7'    ])



# plot
#fig, ax = plt.subplots()

#ax.plot(x2, y2 + 2.5, 'x', markeredgewidth=2)
#ax.plot(x, y, linewidth=2.0)
#ax.plot(x2, y2 - 2.5, 'o-', linewidth=2)

#ax.set(xlim=(0, 8), xticks=np.arange(1, 8), ylim=(0, 8), yticks=np.arange(1, 8))

#plt.show()














#x=[  'Python()','Python I','Matlab()','Matlab I','Java I','C++ I'] 
#y=[ [60,0], [60,0], [60,0, [60,0], [60,0, 0] 
  
  
#   --- Python --- 
# polyfit() X[ 6 ] *  100  result:  [-0.10342358  0.94377887]
# time:  0.0071337223052978516 [sek.]

#y[0]= 0.0071337223052978516

# implementation X[ 6 ] *  100  w1:  -0.10342358399068464 , w0:  0.9437788684884201
# time:  0.0005447864532470703 [sek.]

#y[1]= 0.0005447864532470703

#    --- Matlab ---
# Polyfit:  X[6] * cycles: 1000 
# result: a:0.943779, a:-0.103424


#y[2]=0.114633
# implemented:  X[6] * cycles: 1000 
# result: w0:0.943779, w1:-0.103424

#y[3]=0.002701
# --- Java  ---
# X[6] * 100
# time: 0.0 [sek.],  result: [-0.10342358399068464, 0.9437788684884201]
 
#y[4]=0.0
#  --- C++ ---
#  X[20] * 100
#  time: 6e-06 [sek.],  w0: -0.103424, w1: 0.943779

#y[5]=6e-06
  
  
plt.savefig( '../000.fig/fig01a.pdf',dpi=400 ) 
plt.show()
plt.close()
