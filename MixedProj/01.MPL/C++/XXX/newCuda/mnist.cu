#include <cmath>
#include <math.h>
#include <stdlib.h>

#include <iostream>
#include <cerrno>
#include <cstring>
#include <cfenv>

#include "NeuralNetwork.cuh"
#include "loadcsv.cuh"
#include "load_mnist.cuh"
#include <Eigen/Core>
#include <Eigen/Dense>



int main() {

        //struct to load MNIST
	MNISTData mnist;

        //importing MNIST
	try {
		mnist = load_mnist("train-images.idx3-ubyte", "train-labels.idx1-ubyte", "t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}

	std::cout <<"!!!";
        //Building Model
	NeuralNetwork nn;
	nn.input(mnist.X_train.cols());
	nn.extend(64, "tanh", NeuralNetwork::Initializer::Xavier_Uniform);
	nn.extend(64, "tanh", NeuralNetwork::Initializer::Xavier_Uniform);
	nn.extend(10, "softmax", NeuralNetwork::Initializer::Xavier_Uniform);
	nn.assemble( "cross_entropy", 0.01f, 1000, 0.95f);

        //Starting Training
	nn.learn(mnist.X_train, mnist.Y_train, 20, NeuralNetwork::TrainingDevice::GPU, false);

        //Recognizing test digits
	auto predicted{ nn.predict(mnist.X_test) };

        //printing predictions
	for (int i{}; i < predicted.rows(); ++i) {
		std::cout << "Actual: " << mnist.Y_test.row(i) << " Predicted: " << predicted.row(i) << "\n";
	}

        //accuracy calculation
	std::cout << "Accuracy: " << calculateAccuracy(predicted, mnist.Y_test) << "%";

       //exporting trained model (for future predictions or fine-tuning parameters more)
       nn.exportModel("model_mnist.txt");

	return 0;
}

