import matplotlib.pyplot as plt
import numpy as np

plt.title('Trening klasyfikatora MLP zależność czas/dokładność Matlab')
plt.style.use('_mpl-gallery')


x = [3,6,12,24,48,96,192,384,768,1536,3072,6144, 12288, 24576, 49152]
accuracy=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
train_time=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
accuracy1=[0,0,0,0,0,0,0,0,0,0,0,0]
train_time1=[0,0,0,0,0,0,0,0,0,0,0,0]

accuracy[0]=0.140100
train_time[0]=6.034141
accuracy[1]=0.117900
train_time[1]=1.070806
accuracy[2]=0.107600
train_time[2]=1.067278
accuracy[3]=0.153000
train_time[3]=1.316327
accuracy[4]=0.197700
train_time[4]=2.565767
accuracy[5]=0.301400
train_time[5]=4.255906
accuracy[6]=0.388600
train_time[6]=8.296915
accuracy[7]=0.466700
train_time[7]=16.373333
accuracy[8]=0.579100
train_time[8]=32.528957
accuracy[9]=0.701600
train_time[9]=64.798299
accuracy[10]=0.775000
train_time[10]=129.646078
accuracy[11]=0.832300
train_time[11]=259.264455
accuracy[12]=0.881300
train_time[12]=518.902322
accuracy[13]=0.899300
train_time[13]=1040.200728
accuracy[14]=0.914400
train_time[14]=2088.390680







accuracy1[0]=0.187300
train_time1[0]=6.553557
accuracy1[1]=0.504300
train_time1[1]=3.817442
accuracy1[2]=0.724400
train_time1[2]=6.086159
accuracy1[3]=0.843900
train_time1[3]=11.182136
accuracy1[4]=0.887600
train_time1[4]=22.234024
accuracy1[5]=0.929500
train_time1[5]=43.091031
accuracy1[6]=0.944000
train_time1[6]=85.594957
accuracy1[7]=0.963000
train_time1[7]=170.807739
accuracy1[8]=0.969700
train_time1[8]=341.105244
accuracy1[9]=0.969500
train_time1[9]=679.888107
accuracy1[10]=0.976400
train_time1[10]=1358.899528
accuracy1[11]=0.977800
train_time1[11]=2719.826507









plt.plot(  train_time, accuracy, ':', color='tab:green')
plt.plot(  train_time1, accuracy1, ':', color='tab:red')

plt.legend(['dokładność MLP','dokładność CNN']); 
plt.xlabel('czas [s]', size=10) 
plt.ylabel('dokładność [%]', size=10)
plt.savefig( 'czas_dokladnosc_MLP.pdf',dpi=400 )


 
