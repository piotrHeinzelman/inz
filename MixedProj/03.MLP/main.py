import numpy as np
from numpy.random import randn

# sudo pacman -S python-scikit-learn



x1=1+randn(20,5)
x2=-2*+randn(20,5)
x3=3+randn(20,5)
x=np.concatenate((x1, x2, x3),axis=0)
d=np.concatenate(([1]*20, [2]*20, [3]*20),axis=0)

from sklearn.neural_network import ( MLPClassifier )
from sklearn.model_selection import ( train_test_split )

(x_train, x_test, d_train, d_test) = train_test_split( x,d,test_size=0.2  )

net = MLPClassifier(hidden_layer_sizes=[5,2], activation='logistic', max_iter=300, solver='lbfgs' )

net.fit( x_train, d_train )
from sklearn.metrics import accuracy_score

print(f'''Acc: {accuracy_score(d_test, net.predict(x_test)):.3e}''')
print(f'Loss: {net.loss_:.3e}')