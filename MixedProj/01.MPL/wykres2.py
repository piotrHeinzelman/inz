import matplotlib.pyplot as plt
import numpy as np

plt.title('Trening klasyfikatora MLP zależność czas/dokładność')
plt.style.use('_mpl-gallery')






accuracy[3]=0.140100
train_time[3]=6.034141
accuracy[6]=0.117900
train_time[6]=1.070806
accuracy[12]=0.107600
train_time[12]=1.067278
accuracy[24]=0.153000
train_time[24]=1.316327
accuracy[48]=0.197700
train_time[48]=2.565767
accuracy[96]=0.301400
train_time[96]=4.255906
accuracy[192]=0.388600
train_time[192]=8.296915
accuracy[384]=0.466700
train_time[384]=16.373333
accuracy[768]=0.579100
train_time[768]=32.528957
accuracy[1536]=0.701600
train_time[1536]=64.798299
accuracy[3072]=0.775000
train_time[3072]=129.646078
accuracy[6144]=0.832300
train_time[6144]=259.264455
accuracy[12288]=0.881300
train_time[12288]=518.902322
accuracy[24576]=0.899300
train_time[24576]=1040.200728
accuracy[49152]=0.914400
train_time[49152]=2088.390680






bar_width = 0.18
x = np.arange( len(library) )
off = bar_width

# Grouped Bar Plot
plt.bar( x-1.5*off  , train_time, bar_width, label='czas uczenia')
plt.bar( x-0.5*off  , accuracy, bar_width, label='dokładność')

# Adding labels and title
#plt.xlabel('Yolo ')
plt.ylabel('Time[s]')
plt.xticks(x, library) # ,size=5
plt.legend(title='Time[s]')
plt.savefig( 'czas_dokladnosc_MLP.pdf',dpi=400 )
#plt.show()
#plt.close()




