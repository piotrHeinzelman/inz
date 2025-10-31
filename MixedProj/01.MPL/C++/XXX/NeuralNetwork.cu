#include <iostream>
#include <Eigen/Dense>

class NeuralNetwork {
public:
    enum Activation { TANH, SIGMOID } mActivation;
    double mLearningRate;
    std::vector<int> mArchitecture;
    std::vector<Eigen::RowVectorXd*> mNeurons;
    std::vector<Eigen::RowVectorXd*> mErrors;
    std::vector<Eigen::MatrixXd*> mWeights;

    NeuralNetwork(std::vector<int> architecture,
                  double learningRate = 0.01,
                  Activation activation = TANH);
    void init(std::vector<int> architecture,
              double learningRate = 0.01,
              Activation activation = TANH);
    // Additional methods...



void NeuralNetwork::init(std::vector<int> architecture,
                         double learningRate,
                         Activation activation) {
    // Initialization code...
    for (size_t i = 0; i < architecture.size(); ++i) {
        int size = architecture[i] + (i != architecture.size() - 1);
        mNeurons.push_back(new Eigen::RowVectorXd(size));
        mErrors.push_back(new Eigen::RowVectorXd(size));
        mNeurons.back()->setZero();
        if (i < architecture.size() - 1)
            mNeurons.back()->coeffRef(architecture[i]) = 1.0; // Bias neuron
        if (i > 0) {
            mWeights.push_back(new Eigen::MatrixXd(
                architecture[i - 1] + 1, size));
            mWeights.back()->setRandom();
        }
    }
}

void NeuralNetwork::forward(Eigen::RowVectorXd& input) {
    *mNeurons.front() = input;
    for (size_t i = 1; i < mArchitecture.size(); ++i) {
        *mNeurons[i] = (*mNeurons[i - 1]) * (*mWeights[i - 1]);
        // Apply activation function
        mNeurons[i]->head(mArchitecture[i]).unaryExpr(
            [this](double x) { return activation(x); });
    }
}


double NeuralNetwork::activation(double x) {
    if (mActivation == TANH)
        return std::tanh(x);
    else // SIGMOID
        return 1.0 / (1.0 + std::exp(-x));
}


void NeuralNetwork::backward(Eigen::RowVectorXd& output) {
    // Compute output layer error
    *mErrors.back() = output - *mNeurons.back();
    // Backpropagate the error
    for (size_t i = mErrors.size() - 2; i > 0; --i) {
        *mErrors[i] = (*mErrors[i + 1]) * mWeights[i]->transpose();
    }
    // Update weights
    for (size_t i = 0; i < mWeights.size(); ++i) {
        *mWeights[i] += mLearningRate * mNeurons[i]->transpose() * mErrors[i + 1]->unaryExpr(
            [this](double x) { return activationDerivative(x); });
    }
}




void NeuralNetwork::train(Eigen::RowVectorXd& input, Eigen::RowVectorXd& output) {
    forward(input);
    backward(output);
}




}
