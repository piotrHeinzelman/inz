import matplotlib.pyplot as plt
import numpy as np
plt.title('Czas [s] : MLP 5000 epok, 2 warstwy po 64 neuronw') 
plt.style.use('_mpl-gallery')




#    Matlab Arch  GPU
#    Matlab Win10 GPU
#    Matlab Arch  
#    Matlab Win10

x = np.array([1,2,3,4,           10,11,12,13,       20,21,      30,31,32,33            ])
y = np.array([211,206,205,205,   419,425,419,422,   1998, 2089, 2305,2294,2235,2164    ])
colors = np.array(["red","red","red","red", "orange","orange","orange","orange", "red","red", "orange","orange","orange","orange" ])
#"green","blue","yellow","pink","black","orange","purple","beige","brown","gray","cyan","magenta"])

plt.scatter(x, y, c=colors)

plt.show()



#x = np.array(["Matlab Win10", "Matlab ArchLinux", "Matlab Win10 GPU", "Matlab Archlinux GPU"])
#y = np.array([ 3, 8, 1, 10])
#y1 = np.array([ 4, 5, 2, 11])


#plt.barh(x, y, color = "#4CAF50")



#m[0]=2305
#mi[0]=1998
#mg[0]=419
#mgi[0]=211

#m[1]=2294
#mi[1]=1998
#mg[1]=425
#mgi[1]=206


#m[2]=2235
#mi[2]=2089
#mg[3]=419
#mgi[3]=205

#m[3]=2164
#mi[3]=2089
#mg[3]=422
#mgi[3]=205




#plt.plot( x, p,  'bo-', label='Python wbudowany', linewidth=.5 )
#plt.plot( x, m,  'ro', label='Matlab windows 10, IDE', linewidth=.5 )
#plt.plot( x, mi, 'r+', label='Matlab ArchLinux shell', linewidth=.5 )
#plt.plot( x, mg,  'mo', label='Matlab windows 10, IDE GPU', linewidth=.5 )
#plt.plot( x, mgi, 'm+', label='Matlab ArchLinux shell GPU', linewidth=.5 )
#plt.plot( x, j,  'go-', label='Java', linewidth=.5 )
#plt.plot( x, c,  'yo-', label='C', linewidth=.5 )



#plt.legend()
#plt.xscale('log') # 'linear' 'symlog' 'logit' 
#plt.yscale('log') # 'linear' 'symlog' 'logit' 
#plt.ylim( 0.1, 5 )
#plt.xlim( 8  ,  )
#plt.xticks(x,[ '10','10','10','10' ])



plt.savefig( '../000.fig/fig03.pdf',dpi=400 ) 
plt.show()
plt.close()



