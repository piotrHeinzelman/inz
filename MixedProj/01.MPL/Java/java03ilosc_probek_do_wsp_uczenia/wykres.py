import matplotlib.pyplot as plt
import numpy as np
plt.title('Zależność dokładności sieci od współczynnika uczenia') 
plt.style.use('_mpl-gallery')


x=[5, 10, 15, 20, 25, 30, 35, 40 ]
a=[None,None,None,None,None,None,None,None]
b=[None,None,None,None,None,None,None,None]
c=[None,None,None,None,None,None,None,None]
d=[None,None,None,None,None,None,None,None]
e=[None,None,None,None,None,None,None,None]
f=[None,None,None,None,None,None,None,None]
g=[None,None,None,None,None,None,None,None] 
h=[None,None,None,None,None,None,None,None]
i=[None,None,None,None,None,None,None,None]
j=[None,None,None,None,None,None,None,None]
k=[None,None,None,None,None,None,None,None]
l=[None,None,None,None,None,None,None,None]
m=[None,None,None,None,None,None,None,None] 


c[0]=0.5619
c[1]=0.6868
c[2]=0.6464
c[3]=0.6894
c[4]=0.5994
c[5]=0.6555
c[6]=0.6379
c[7]=0.6985

f[0]=0.8067
f[1]=0.8243
f[2]=0.8547
f[3]=0.8684
f[4]=0.8771
f[5]=0.8698
f[6]=0.8762
f[7]=0.8929

i[0]=0.4034
i[1]=0.5871
i[2]=0.6727
i[3]=0.7084
i[4]=0.7451
i[5]=0.7724
i[6]=0.802
i[7]=0.8121


j[0]=0.124
j[1]=0.142
j[2]=0.1629
j[3]=0.1413
j[4]=0.2174
j[5]=0.3277
j[6]=0.2988
j[7]=0.3097

 
k[0]=0.0985
k[1]=0.1125
k[2]=0.1226
k[3]=0.1128
k[4]=0.131
k[5]=0.1201
k[6]=0.1395
k[7]=0.1376

#plt.plot( x, a,  'g.', label='wsp. uczenia = 0.1,     20% danych', linewidth=.5 )
#plt.plot( x, b,  'b:', label='wsp. uczenia = 0.1      50% danych', linewidth=.5 )
plt.plot( x, c,  'g:', label='wsp. uczenia = 0.1     100% danych', linewidth=.5 )
#plt.plot( x, d,  'r.', label='wsp. uczenia = 0.01    20% danych', linewidth=.5 )
#plt.plot( x, e,  'r:', label='wsp. uczenia = 0.01    50% danych', linewidth=.5 )
plt.plot( x, f,  'r-', label='wsp. uczenia = 0.01   100% danych', linewidth=.5 )
#plt.plot( x, g,  'g.', label='wsp. uczenia = 0.001   20% danych', linewidth=.5 )
#plt.plot( x, h,  'g:', label='wsp. uczenia = 0.001   50% danych', linewidth=.5 )
plt.plot( x, i,  'b-', label='wsp. uczenia = 0.001  100% danych', linewidth=.5 )
plt.plot( x, j,  'm:', label='wsp. uczenia = 0.0001 100% danych', linewidth=.5 )
plt.plot( x, k,  'y:', label='wsp. uczenia = 0.00001 100% danych', linewidth=.5 )



plt.legend()
#plt.xscale('log') # 'linear' 'symlog' 'logit' 
#plt.yscale('log') # 'linear' 'symlog' 'logit' 
plt.ylim( 0, 1 )
plt.xticks(x,[ '5','10', '20', '30','50','75', '100', '125'    ])

  
plt.savefig( 'wyk.pdf',dpi=400 ) 
plt.show()
plt.close()



