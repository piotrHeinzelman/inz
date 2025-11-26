import matplotlib.pyplot as plt
import numpy as np

plt.title('Proces uczenia klasyfikatora MLP')
plt.style.use('_mpl-gallery')


x = [3,6,12,24,48,96,192,384,768]
accuracy=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
train_time=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

accuracy[0]=0.30
train_time[0]=5
accuracy[1]=0.39
train_time[1]=10
accuracy[2]=0.51
train_time[2]=15
accuracy[3]=0.58
train_time[3]=20
accuracy[4]=0.63
train_time[4]=25
accuracy[5]=0.62
train_time[5]=30
accuracy[6]=0.68
train_time[6]=35
accuracy[7]=0.73
train_time[7]=40
accuracy[8]=0.75
train_time[8]=45
accuracy[9]=0.83
train_time[9]=300
accuracy[10]=0.82
train_time[10]=500
accuracy[11]=0.83
train_time[11]=700
accuracy[12]=0.84
train_time[12]=800
accuracy[13]=0.84
train_time[13]=1000
accuracy[14]=0.85
train_time[14]=1230


plt.plot(  train_time, accuracy, ':', color='tab:green')
#plt.plot(  train_time1, accuracy1, ':', color='tab:red')

plt.legend(['klasyfikator Java']);
plt.xlabel('ilość eopk')
plt.ylabel('dokładność [%]')
plt.savefig( 'przebieg_uczenia_MLP_JavaVsMatlab.pdf',dpi=400 )
