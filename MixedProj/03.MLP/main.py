# sudo pacman -S python-scikit-learn

import numpy as np
from numpy.random import randn


from sklearn.neural_network import ( MLPClassifier )
from sklearn.model_selection import ( train_test_split )

from sklearn.metrics import accuracy_score

from data.readdata import load_mnist


x_train, y_train = load_mnist( kind='train' )
x_test, y_test = load_mnist( kind='t10k' )


print( x_train.size )
print( x_test.size )

( x_train, x_trash, y_train, y_trash) = train_test_split( x_train, y_train, test_size=0.1 ) 
( x_test, x_trash, y_test, y_trash)   = train_test_split( x_test , y_test , test_size=0.1 )

print( x_train.size )
print( x_test.size )



for i in range ( 50, 750, 10 ):
    net = MLPClassifier( hidden_layer_sizes=[32,32,10], activation='logistic', max_iter=i, solver='lbfgs' )
    net.fit( x_train, y_train )
    score =  accuracy_score( y_test, net.predict( x_test ))   
    loss  =  net.loss_ 

    print( '# cycles:   (%i) ' % i )
    print( '# Accuracy score: (%f) ' % score )
    print( '# Net loss:       (%f) ' % loss  )
    print( 'p[]=[ %i, %f ] ' % ( i, score ) )
#    print(i)

