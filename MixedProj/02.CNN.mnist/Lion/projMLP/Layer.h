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
//#include "tools.cu"

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
                    W[i][j]=(-1.0+0.01*( rand()%200 )); //(m*0.5);//m;
                    //std::cout<<W[i][j]<<std::endl;
                    //  W[i][j]=0.01*( rand()%200 );
                }
            }
        }
    }




    double getMax( const double Y[], int len ) {
        double max=Y[0];
        for (int i=1;i<len;i++) {
            if (Y[i]>max) { max=Y[i]; }
        }
        return max;
    }

    double getSum( const double Y[], int len ) {
        double sum=0.0;
        for (int i=0;i<len;i++) {
            sum+=Y[i];
        }
        return sum;
    }

    void expAryminusMax(  double Y[], double max ,int len ) {
        for (int i=0;i<len;i++) {
            Y[i]=std::exp(Y[i]-max);
        }
    }

    void mullAryByValue(  double Y[], double value ,int len ) {
        for (int i=0;i<len;i++) {
            Y[i]=Y[i]/value;
        }
    }






      //type1
    void Forward ( double Z[] , const double X[]){
        for (int i=0;i<n;i++) { Z[i]=0.0; myY[i]=0.0;}
        switch(type){
            case 1: case 3: { //PERCEPTRON_SIGMOID
                for (int i=0;i<n;i++){
                    for (int j=0;j<m;j++){
                        myY[i]+=X[j]*W[i][j];
                    }
                    if (type==1) {
                        double z=F(myY[i]);
                        dF[i]=z*(1-z);
                        Z[i]=z;
                    }
                    if (type==3) {
                        dF[i]=1;
                        Z[i]=myY[i];
                    }
                }
                // save X * mu for backprop;
                for (int j=0;j<m;j++) {
                    muX[j]=mu*X[j];
                }
                if (type==1) break;
                             //PERCEPTRON_SOFTMAX_MULTICLASS
                             //std::cout<<" Z[" << 0 <<"]: " << Z[0] << std::endl;

                double max = getMax( Z, n );
                 expAryminusMax(Z, max, n );
                double sum = getSum( Z, n );
                mullAryByValue( Z, sum ,n );

                break;
            }
        }
    }



    double F  ( double y) const {
        switch(type){
            case 1: { //PERCEPTRON_SIGMOID
                return y*(1-y);
            }
            case 3: { //PERCEPTRON_SOFTMAX_MULTICLASS
                return y;
            }
        }
        return 0.0;
    }



    void Backward ( double eOut[], const double eIn[] ){
        switch (type) {
            case 1/*PERCEPTRON_SIGMOID*/: case 3/*PERCEPTRON_SOFTMAX_MULTICLASS*/: {
                for (int j=0;j<m;j++){ eOut[j]=0.0;}
                for (int i=0;i<n;i++){
                    dFE[i]=eIn[i]*dF[i];     // prepare dFE from dF[neuron] * eIn[neuron]
                }
                // SYNCHRO !!!!
                for (int i=0;i<n;i++){
                    for (int j=0;j<m;j++) {
                        eOut[j]+=dFE[i]*W[i][j];  // prepare eOUT ( sum by M  dFE[neuron]*W[neuron][m] )
                        W[i][j]+=dFE[i]*muX[j];   // update Weight dFE * X * um;
                        //if (i==0) { std::cout<<"dFE[i]: "<<dFE[i]<<" muX"<<muX[j]<<std::endl; }
                    }
                }
            }
        }
    }


    double crossEntropyMulticlassError( double* Z, double * S){
        double out = 0.0;
        for ( int i=0;i<n; i++ ){
            out += S[i]*log(Z[i]);
            //std::cout<<"S["<<i<<"]: "<<S[i]<<", Z["<<i<<"]:"<< Z[i]<<std::endl;
        }
        return -1*out;
    }

    /*

    double sum = 0.0;
        for ( int i=0;i<n; i++ ){
            sum+= S[i]*log(Z[i]) + (1-S[i])*log(1-Z[i]);
        }
        return sum/n;

   */

    void vectorSsubZ(double* resultSsubZ, double* S, double *Z) {
        for ( int i=0;i<n; i++ ){
            resultSsubZ[i]=S[i]-Z[i];
        }
    }


    int getN() {
        return n;
    }
};

#endif //INZ_LAYER_H