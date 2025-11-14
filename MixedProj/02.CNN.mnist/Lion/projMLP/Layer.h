//
// Created by john on 11/13/25.
//

#ifndef INZ_LAYER_H
#define INZ_LAYER_H

//#define PERCEPTRON_SIGMOID 1
//#define PERCEPTRON_CROSSENTROPY_BINARY 2
//#define PERCEPTRON_SOFTMAX_MULTICLASS 3

#include <iostream>
#include <cmath>

class Layer {
   // type 1=sigmoid, 3=softmaxMultiClass, 10=flatten, 20=CNN
   private:
       const int type;
       const int n;
       const int m;
       double** W;
       double* muX;
       double* dF;
       double* dFE;
       double* myY;
       float mu=0.01;


   public:
    Layer(  int type_,  int n_,  int m_ )    // n - neurons num, output size , W[n][m], Y[n]
                                        // m - input size X[m]
  : type{type_}
    , n{n_}
    , m{m_}
    {
        // init Weights
        if (type<4){ // sigmoid, type 1=sigmoid, 2=sigmod_CrossEntropy_Binary, 3=softmax
            srand(time(0));
            W = new double*[n];
            dF = new double [n];
            dFE = new double [n];
            myY = new double [n];
            muX = new double [m];
            for ( int i=0;i<n;i++){
                W[i]=new double[m];
                for (int j=0;j<m;j++){
                    W[i][j]=(-1.0+0.01*( rand()%200 ))/1;
                    //  W[i][j]=0.01*( rand()%200 );
                }
            }
        }
    }

      //type1
    void Forward ( double Z[] , const double X[]){
        switch(type){
            case 1: { //PERCEPTRON_SIGMOID
                for (int i=0;i<n;i++){
                    double y=0.0;
                    for (int j=0;j<m;j++){
                        y+=X[j]*W[i][j];
                    }
                    double z=F(y);
                    dF[i]=z*(1-z);
                    Z[i]=z;
                }
                // save X * mu for backprop;
                for (int j=0;j<m;j++) {
                    muX[j]=X[j]*mu;
                }
                break;
            }
            case 3: { //PERCEPTRON_SOFTMAX_MULTICLASS
                for (int i=0;i<n;i++) {
                    myY[i]=0.0;
                    for (int j=0;j<m;j++){
                        myY[i]+=X[j]*W[i][j];
                    }
                }
                const double maxOfY = getMax( myY );
  // printVec100( &X[0] ); // <<<----- !!!
                double sumOfY = 0.0;
                //df=1

                for (int i=0;i<n;i++) {
                    myY[i]=std::exp( myY[i]- maxOfY );
                    sumOfY+=myY[i];
                }
                for (int i=0;i<n;i++) {
                    dF[i]=1.0;
                    Z[i]=myY[i]/sumOfY;
                }
                break;
            }
        }
    }



    double F  ( double y) const {
        switch(type){
            case 1: { //PERCEPTRON_SIGMOID
                return y*(1-y);
            }
        }
        return 0.0;
    }



    void Backward ( double eOut[], const double eIn[] ){
        switch (type) {
            case 1/*PERCEPTRON_SIGMOID*/: case 3/*PERCEPTRON_SOFTMAX_MULTICLASS*/: {
                for (int i=0;i<n;i++){
                    eOut[i]=0.0;
                    dFE[i]=eIn[i]*dF[i];     // prepare dFE from dF[neuron] * eIn[neuron]
                }
                // SYNCHRO !!!!
                for (int i=0;i<n;i++){
                    for (int j=0;j<m;j++) {
                        W[i][j]+=dFE[i]*muX[j];   // update Weight dFE * X * um;
                        eOut[j]+=dFE[i]*W[i][j];  // prepare eOUT ( sum by M  dFE[neuron]*W[neuron][m] )
                        //std::cout<<"eIn["<<i<<"]:"<<eOut[i]<<std::endl;
                    }
                }
            }
        }
    }



    double getMax( const double Y[] ) {
        double max=Y[0];
        for (int i=1;i<n;i++) {
            if (Y[i]>max) { max=Y[i]; }
        }
        return max;
    }




    double crossEntropyMulticlassError( double* Z, double * S){
        double out = 0.0;
        for ( int i=0;i<n; i++ ){
            out += S[i]*log(Z[i]);
        }
        return -1*out;
    }


    void vectorSsubZ(double* resultSsubZ, double* S, double *Z) {
        for ( int i=0;i<n; i++ ){
            resultSsubZ[i]=S[i]-Z[i];
        }
    }



};

#endif //INZ_LAYER_H