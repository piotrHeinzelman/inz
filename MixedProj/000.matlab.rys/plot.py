import matplotlib.pyplot as plt

# make data

#x = [0,1,2,3]
x=["Python","Matlab","Java","C++"]
y=[0,0,0,0]


y[0]=0.001
y[1]=0.01
y[2]=0.1
y[3]=1

#plt.plot(x,y)
plt.barh(x,y);
plt.show();

# x = np.arange(20, 65535)
# my = [ 0.11     , 0.57   ]
# py = [ 0.036    , 3.16 ]
#  jy = [ 0.003    , 0.111  ]
# cy = [ 0.000136 , 0.41   ]
# y = np.vstack([my, py, jy, cy])

# plot
# fig, ax = plt.subplots()

# ax.stackplot(x, y)

# ax.set(xlim=(0, 8), xticks=np.arange(1, 8), ylim=(0, 8), yticks=np.arange(1, 8))

# plt.show()


import matplotlib.pyplot as plt 
# data to display on plots 
#x = [3, 1, 3, 12, 2, 4, 4] 
#y = [3, 2, 1, 4, 5, 6, 7] 

# This will plot a simple bar chart
#plt.bar(x, y)

# Title to the plot
#plt.title("Bar Chart")

# Adding the legends
#plt.legend(["bar"])
#plt.show()


plt.savefig('01.pdf')
plt.savefig('01.jpg')
plt.savefig('01.png',dpi=150)



#import matplotlib.pyplot as plt

#categories = ['A', 'B', 'C', 'D', 'E']
#values = [23, 45, 56, 78, 32]
#colors = ['red', 'green', 'blue', 'yellow', 'purple']

#plt.figure(figsize=(10, 6))
#plt.bar(categories, values, color=colors)
#plt.title('Bar Chart with Custom Colors - how2matplotlib.com')
#plt.xlabel('Categories')
#plt.ylabel('Values')
#plt.xticks(rotation=45, ha='right')
#plt.tight_layout()
#plt.show()
