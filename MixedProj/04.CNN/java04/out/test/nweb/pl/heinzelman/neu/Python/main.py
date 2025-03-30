# https://github.com/TheIndependentCode/Neural-Network/tree/master

import numpy as np
from scipy import signal
#from layer import Layer

# class Convolutional(Layer):
class Convolutional():
    def __init__(self, input_shape, kernel_size, depth):
        input_depth, input_height, input_width = input_shape
        self.depth = depth
        self.input_shape = input_shape
        self.input_depth = input_depth
        self.output_shape = (depth, input_height - kernel_size + 1, input_width - kernel_size + 1)
        self.kernels_shape = (depth, input_depth, kernel_size, kernel_size)
        self.kernels = np.random.randn(*self.kernels_shape)
        self.biases = np.random.randn(*self.output_shape)

    def forward(self, input):
        self.input = input
        self.output = np.copy(self.biases)
        for i in range(self.depth):
            for j in range(self.input_depth):
                self.output[i] += signal.correlate2d(self.input[j], self.kernels[i, j], "valid")
        return self.output

    def backward(self, output_gradient, learning_rate):
        kernels_gradient = np.zeros(self.kernels_shape)
        input_gradient = np.zeros(self.input_shape)

        for i in range(self.depth):
            for j in range(self.input_depth):
                kernels_gradient[i, j] = signal.correlate2d(self.input[j], output_gradient[i], "valid")
                input_gradient[j] += signal.convolve2d(output_gradient[i], self.kernels[i, j], "full")

        self.kernels -= learning_rate * kernels_gradient
        self.biases -= learning_rate * output_gradient
        return input_gradient

x=[1,2,3,4,5,6,7,8,9]
x = np.reshape(x, (3,3) )
print(x	)

f = [1,2,3,4]
f = np.reshape(f,(2,2))
print(f)

print()
print('FORWARD: one flat layer (add all layer & bias)')
print( signal.correlate2d( x , f , "valid"  ) )
print()


delta=[.1, .2, .3, .8 ]
delta=np.reshape(delta,(2,2))

print('Kernel gradient SUM: every channel: UPDATE WEIGHT ')
print( signal.correlate2d( x, delta, "valid") )
print()

print('outputDelta SUM: for all channel:  SEND FORWARD ')
print( signal.convolve2d( delta, f, "full" ) )
print()

print('bias update: = delta for channel/filter')
print( delta )
