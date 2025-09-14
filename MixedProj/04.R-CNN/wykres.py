import matplotlib.pyplot as plt
import numpy as np
plt.title('Regresja liniowa: polyfit  X[6] x 100')
plt.style.use('_mpl-gallery')


x=["Yolo2", "Yolo3", "Yolo4", "YoloX"]
d1=[None,None,None,None]
d2=[None,None,None,None]
d3=[None,None,None,None]
d4=[None,None,None,None]
e1=[None,None,None,None]
e2=[None,None,None,None]
e3=[None,None,None,None]
e4=[None,None,None,None]
f1=[None,None,None,None]
f2=[None,None,None,None]
f3=[None,None,None,None]
f4=[None,None,None,None]

#################################

# net: tiny-yolov2-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :2.218212; 
# load image time: 0.082333; detect object time: 1.859902

d1[0]=2.218212
d1[1]=0.082333
d1[2]=1.859902
d1[3]=0.000000
# net: tiny-yolov3-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :1.219350; 
# load image time: 0.011035; detect object time: 1.153462

d2[0]=1.219350
d2[1]=0.011035
d2[2]=1.153462
d2[3]=0.000000
# net: tiny-yolov4-coco; task:dog1; class: ? score: 0.000000;  prepare detectortime: :0.712956; 
# load image time: 0.010958; detect object time: 0.780289

d3[0]=0.712956
d3[1]=0.010958
d3[2]=0.780289
d3[3]=0.000000
# net: tiny-coco; task:dog1; class: dog score: 0.762755;  prepare detectortime: :2.460936; 
# load image time: 0.008333; detect object time: 1.263330

d4[0]=2.460936
d4[1]=0.008333
d4[2]=1.263330
d4[3]=0.762755
# net: tiny-yolov2-coco; task:dog2; class: dog score: 0.879725;  prepare detectortime: :0.523305; 
# load image time: 0.020615; detect object time: 0.318380

e1[0]=0.523305
e1[1]=0.020615
e1[2]=0.318380
e1[3]=0.879725
# net: tiny-yolov3-coco; task:dog2; class: dog score: 0.936445;  prepare detectortime: :0.402173; 
# load image time: 0.007506; detect object time: 0.315337

e2[0]=0.402173
e2[1]=0.007506
e2[2]=0.315337
e2[3]=0.936445
# net: tiny-yolov4-coco; task:dog2; class: dog score: 0.588947;  prepare detectortime: :0.367192; 
# load image time: 0.005595; detect object time: 0.342227

e3[0]=0.367192
e3[1]=0.005595
e3[2]=0.342227
e3[3]=0.588947
# net: tiny-coco; task:dog2; class: dog score: 0.922000;  prepare detectortime: :1.409633; 
# load image time: 0.005538; detect object time: 0.640414

e4[0]=1.409633
e4[1]=0.005538
e4[2]=0.640414
e4[3]=0.922000
# net: tiny-yolov2-coco; task:team; class: person score: 0.707635;  prepare detectortime: :0.335716; 
# load image time: 0.050147; detect object time: 0.182345

f1[0]=0.335716
f1[1]=0.050147
f1[2]=0.182345
f1[3]=0.707635
# net: tiny-yolov3-coco; task:team; class: person score: 0.949395;  prepare detectortime: :0.301095; 
# load image time: 0.015740; detect object time: 0.164364

f2[0]=0.301095
f2[1]=0.015740
f2[2]=0.164364
f2[3]=0.949395
# net: tiny-yolov4-coco; task:team; class: person score: 0.718039;  prepare detectortime: :0.340054; 
# load image time: 0.011473; detect object time: 0.279326

f3[0]=0.340054
f3[1]=0.011473
f3[2]=0.279326
f3[3]=0.718039
# net: tiny-coco; task:team; class: person score: 0.878444;  prepare detectortime: :1.250326; 
# load image time: 0.006704; detect object time: 0.580992

f4[0]=1.250326
f4[1]=0.006704
f4[2]=0.580992
f4[3]=0.878444


#################



plt.plot( x, d1,  'bo-', label='task: Dog 1', linewidth=.5 )
plt.plot( x, d2,  'bo-', label='task: Dog 2', linewidth=.5 )
plt.plot( x, d3,  'bo-', label='task: Team', linewidth=.5 )



plt.legend()
plt.xscale('log') # 'linear' 'symlog' 'logit'
plt.yscale('log') # 'linear' 'symlog' 'logit'
plt.ylim( 0.1, 5 )
#plt.xticks(x,[ '6','6*10^1','6*10^2','6*10^3','6*10^4','6*10^5','6*10^6','6*10^7'    ])


# plt.savefig( '../000.fig/04_RCNN_MAT.pdf',dpi=400 )
plt.savefig( '04_RCNN_MAT.pdf',dpi=400 )
plt.show()
plt.close()



