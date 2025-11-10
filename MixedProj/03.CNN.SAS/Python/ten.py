import tensorflow as tf
import numpy as np
import time
from tensorflow import keras
from tensorflow.keras.backend import clear_session
from tensorflow.keras.utils import to_categorical

"""
physical_devices = tf.config.list_physical_devices('GPU')
if physical_devices:
   for gpu in physical_devices:
      tf.config.experimental.set_memory_growth(gpu, True)
      print(gpu.device_type)

device_name = tf.test.gpu_device_name()
print(device_name)
"""


# params
epochs = 2 # 50
percent = 1 # 30
num_classes = 2


def readFileX ( fileName ):
    file=open( fileName, 'rb' )
    data=np.fromfile( fileName, np.uint8, percent*8*240*240*3, '')
    data=data.reshape(percent*8, 240*240*3)
    data=(data/255)
    file.close()
    return data

def readFileY ( fileName ):
    file=open( fileName, 'rb' )
    len=percent*8
    data=np.fromfile( fileName, np.uint8, len, '' )
    file.close()
    return data



def CNN():
   NUMBER_OF_CLASSES = 10
   return keras.models.Sequential([
      keras.layers.Input(shape=(240,240,3) ),
      keras.layers.Conv2D(name='conv1', filters=20, kernel_size=(5,5), activation='relu' ),
      keras.layers.BatchNormalization(),
      keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
      keras.layers.Flatten(),
      keras.layers.Dense(num_classes, activation='softmax')
])


"""

       # 1st convolutional layer
       self.conv1 = nn.Conv2d(in_channels=in_channels, out_channels=32, kernel_size=7, padding=3) # , padding=1)
       self.norm1 = nn.BatchNorm2d(32)
       self.pool1 = nn.MaxPool2d(kernel_size=2, stride=2)

       self.conv2 = nn.Conv2d(in_channels=32, out_channels=64, kernel_size=5, padding=3)
       self.norm2 = nn.BatchNorm2d(64)
       self.pool2 = nn.MaxPool2d(kernel_size=2, stride=2)

       self.conv3 = nn.Conv2d(in_channels=64, out_channels=128, kernel_size=3, padding=1)
       self.norm3 = nn.BatchNorm2d(128)
       self.pool3 = nn.MaxPool2d(kernel_size=2, stride=2)

       self.conv4 = nn.Conv2d(in_channels=128, out_channels=256, kernel_size=3, padding=1)
       self.norm4 = nn.BatchNorm2d(256)
       self.pool4 = nn.MaxPool2d(kernel_size=2, stride=2)

       self.conv5 = nn.Conv2d(in_channels=256, out_channels=256, kernel_size=1)
       self.norm5 = nn.BatchNorm2d(256)
       self.pool5 = nn.MaxPool2d(kernel_size=1)


       self.conv6 = nn.Conv2d(in_channels=256, out_channels=18, kernel_size=1)
       self.norm6 = nn.BatchNorm2d(18)
       self.pool6 = nn.MaxPool2d(kernel_size=2)

       self.conv7 = nn.Conv2d(in_channels=18, out_channels=8, kernel_size=1)
       self.norm7 = nn.BatchNorm2d(8)
       self.pool7 = nn.MaxPool2d(kernel_size=2)

       self.conv8 = nn.Conv2d(in_channels=8, out_channels=6, kernel_size=1)
       self.norm8 = nn.BatchNorm2d(6)
       self.pool8 = nn.MaxPool2d(kernel_size=2)

       self.conv9 = nn.Conv2d(in_channels=6, out_channels=2, kernel_size=1)
       self.norm9 = nn.BatchNorm2d(2)
       self.pool9 = nn.MaxPool2d(kernel_size=1)



       # 2nd convolutional layer
       # self.conv2 = nn.Conv2d(in_channels=8, out_channels=16, kernel_size=3, padding=1)
       # Fully connected layer
       self.fc1 = nn.Linear( 2 , num_classes ) 
"""


start1=time.time()
trainX = readFileX ('../../../../inz_Hidden/SAS/out.bin' )
trainY = readFileY ('../../../../inz_Hidden/SAS/out.class' )


trainX = trainX.astype("float32")
trainY = trainY.astype("int")

trainX = trainX.reshape(percent*8, 240,240,3).astype("float32")

end1=time.time()
timeLoadData=end1-start1


model = CNN()
model.summary()

model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])


start=time.time()
#with tf.device('/device:GPU:0'):
model.fit(trainX, trainY, epochs=epochs, verbose=0)

end=time.time()
timeTrain=end-start


start3=time.time()
#with tf.device('/device:GPU:0'):
score = model.evaluate(testX, testY, verbose=1 )
end3=time.time()
timeForward=end3-start3

clear_session()



print("# CNN 48000 img, epoch:",epochs)
print("# timeLoadData: ",timeLoadData)
print("# timeTrain: ",timeTrain)
print("# timeForward: ", timeForward)
print("Test loss:", score[0])
print("Test accuracy:", score[1])


