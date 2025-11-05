#include "NeuralNetwork.h"
#include "load_mnist.h"
#include "loadcsv.h"
#include "ctime"




#include <Eigen/Core>
/*
#include <iostream>

int main()
{
    std::cout << "Hello Eigen\t";
    std::cout << EIGEN_WORLD_VERSION << "." << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << "\n";
    std::cout << "Hello nvcc\t";
    std::cout << __CUDACC_VER_MAJOR__ << "." << __CUDACC_VER_MINOR__ << "." << __CUDACC_VER_BUILD__ << "\n";
    return 0;
}
*/







int main(){

//--------------LOAD CSV FILES------------------------

    // Data data {load_csv("filename.csv", "label_column", 0.8)}; //--> change training data ratio from
                                                                   // 0.8 to something else if you want

    // MatrixXd X_train {toMatrixXd(data.X_train)};
    // MatrixXd X_test {toMatrixXd(data.X_test)};
    // VectorXd Y_train {toVectorXd(data.Y_train)};
    // VectorXd Y_test {toVectorXd(data.Y_test)};

//you can use toOneHot() to one hot encode the labels

//--------------LOAD MNIST----------------------------

    int num_images_train, rows_train, cols_train, num_labels_train;
    int num_images_test, rows_test, cols_test, num_labels_test;


    //change path to where your MNIST data is
    MatrixXd train_images = load_mnist_images("../../../../inz_Hidden/MNIST/train-images-idx3-ubyte", num_images_train, rows_train, cols_train);
    MatrixXd test_images = load_mnist_images( "../../../../inz_Hidden/MNIST/t10k-images-idx3-ubyte", num_images_test, rows_test, cols_test);
    VectorXd train_labels = load_mnist_labels("../../../../inz_Hidden/MNIST/train-labels-idx1-ubyte", num_labels_train);
    VectorXd test_labels = load_mnist_labels( "../../../../inz_Hidden/MNIST/t10k-labels-idx1-ubyte", num_labels_test);

    MatrixXd train_labels_oh {toOneHot(train_labels, 10)};
    MatrixXd test_labels_oh {toOneHot(test_labels, 10)};

    NeuralNetwork nn {{784, 64, 64, 10}, {"relu", "relu", "softmax"}};
    clock_t before=clock();
    nn.learn(train_images, train_labels_oh, 1024, 0.01, 32, "cross_entropy_loss", true);
    clock_t trainTime=clock()-before;
    std::cout << "TrainTime:" << (float) trainTime/CLOCKS_PER_SEC << "\n";


    before=clock();
    MatrixXd pred {nn.predict(test_images)};
    clock_t predTime=clock()-before;
    std::cout << "PredictionTime:" << (float) predTime/CLOCKS_PER_SEC << "\n";
    return 1;

    for (int i {}; i<test_labels_oh.rows(); ++i){
        std::cout<<"Actual: "<<test_labels_oh.row(i)<<" Predicted: ";
        for (int j {}; j<10; ++j){
            std::cout<<std::round(pred(i,j))<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"Accuracy: "<<accuracy(test_labels_oh, pred);

    return 0;
}
