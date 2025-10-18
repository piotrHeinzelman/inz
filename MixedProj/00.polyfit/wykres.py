import matplotlib.pyplot as plt
import numpy as np
plt.title('Regresja liniowa: polyfit 64.000.000')
plt.style.use('_mpl-gallery')


x=[2,4,6,8,10]
p=[.238  , .389 , .451 , 10.73 , 0.29  ]
q=[.382  , .273 , .163 , 19.61 , 51.35 ]
r=[.62   , .662 , .614 , 30.34 , 51.64 ]

plt.plot( x, p,  'bo:', label='czas przygotowania danych', linewidth=.5 )
plt.plot( x, q, 'ro:', label='wykonanie obliczen', linewidth=.5 )
plt.plot( x, r, 'go:', label='całkowity czas wykonania zadania', linewidth=.5 )


plt.legend()
plt.xticks(x,[ 'C++','Matlab','Java','Python[]','Python np.array'])

plt.savefig( 'wykres_regres.pdf',dpi=400 )
plt.show()
plt.close()



