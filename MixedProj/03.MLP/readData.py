# from: Sebastian Raschka Python Machine learning i deep learning p. 381

import os
import struct
import numpy as np

def load_mnist (path, kind='train'):
    labels_path = os.path.join(path, '%s-labels-idx1-ubyte' % kind )
    images_path = os.path.join(path, '%s-images-idx3-ubyte' % kind )

    with open (labels_path, 'rb') as lbpath:
        magic, n = struct.unpack('>II', lbpath.read(8)) 
        labels = np.fromfile(lbpath, dtype=np.uint8 )

    with open(images_path, 'rb') as imgpath:
        magic, num, rows, cols = struct.unpack('>IIII',imgpath.read(16))
        images = np.fromfile(imgpath, dtype=np.uint8).reshape(len(labels),784)
        images= ((images / 255.) -.5 )*2

    return images, labels


X_train, y_train = load_mnist('/home/john/INZ/inz/MixedProj/03.MLP/data/', kind='train')
print ('rzedy: %d, kolumny: %d' % (X_train.shape[0], X_train.shape[1]))

X_train, y_train = load_mnist('/home/john/INZ/inz/MixedProj/03.MLP/data/', kind='t10k')
print ('rzedy: %d, kolumny: %d' % (X_train.shape[0], X_train.shape[1]))



print ( X_train[0] )

