//
// Created by john on 16.11.2025.
//

#include "tens.h"

#include <iostream>
#include <cmath>

//int H, W, C;
//double* data;
//  data = new double[H*W*C];

int tens::getN(){ return this->N; };
int tens::getH(){ return this->H; };
int tens::getW(){ return this->W; };
int tens::getC(){ return this->C; };

double tens::getPoint( int h, int w, int c) {
    if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return 0;
       return data[1*HWC + h*WC + w*C + c];// <<" "; //   getPoint(h,w,c)
};

double tens::getPoint( int n, int h, int w, int c) {
    if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return 0;
    return data[n*HWC + h*WC + w*C + c];//getPoint(n,h,w,c)
};


void tens::setPoint(int h, int w, int c, double value) {
   // if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return;
    data[1*HWC + h*WC + w*C + c]=value;
};

void tens::setPoint(int n, int h, int w, int c, double value) {
    //if ( n>N || h>=H || w>=W || c>=C || n<0 || h<0 || w<0 || c<0 ) return;
    data[n*HWC + h*WC + w*C + c]=value;
};

void tens::rand(int min, int max) {
    srand(time(0));
    int delta=max-min;
    for (int i=0;i<NHWC;i++) data[i]=( min+0.001*( std::rand()%(delta*1000) )); //(m*0.5);//m;;
};

void tens::addN1( tens* const y ) {
    for (int i=0;i<NHWC;i++){
        data[i]+=y->data[i];
    }
}


void tens::mulN1( double mul ){
    for ( int i=0;i<HWC;i++){
        data[i]=mul*data[i];
    }
}

void tens::toFlat() {
   N=1;
   H=NHWC;
   W=1;
   C=1;
   HWC=H*W*C;
   WC=W*C;
}


void tens::to3D( int N, int H, int W, int C ) {
    this->N=N;
    this->H=H;
    this->W=W;
    this->C=C;
    NHWC=N*H*W*C;
    HWC=H*W*C;
    WC=W*C;
}



void tens::myPrint() {
    for (int n=0;n<N;n++) {
        std::cout<<std::endl<<"n: "<<n<<std::endl;
        for (int h=0;h<H;h++) {
            std::cout<<" | ";
            for (int wc=0;wc<(W*C);wc++) {
                std::cout << data[n*HWC + h*WC + wc] <<" "; //   getPoint(n,h,w,c) // n*HWC + h*WC + w*C + c]
            }
            std::cout<<" | "<<std::endl;
        }std::cout<<std::endl;
    }
};


void tens::WX( tens* result, tens* dF, tens* X ) { //H, W, 1   W[H,W,1]  X[H,1,1], result Y[H,1,1]
    int Xn=X->getN();// X images number

    double y=0;
    double z=0;
    for (int n=0; n<Xn; n++) {

        for (int h=0; h<H; h++) {
            y=0;
            for (int wc=0;wc<WC;wc++) {
                y += ( data[ h*WC + wc ]  *   X->data[ (n*WC + wc) ]);
            }
            z  = 1.0/(1.0 + std::exp(-y));
                dF->data[ (n*H + h) ] =  (z*(1-z));
            result->data[ (n*H + h) ] = z;        // <- W IS OK !!! (shape change)
            //result->showShape();

            //std::cout<< "n:"<<n <<", h:"<< h <<", w:"    << " : " <<z*(1-z) <<std::endl;
            // F'
        }
    }
    //for (int i=0;i<9999;i++){result->data[i]=9;}
};









void tens::WXSoftmax( tens* result, tens* X ) {
    int Xn=X->getN();// X images number
    double y=0;
    double sum=0;
    for (int n=0;n<Xn;n++) {

        sum=0;
        for (int h=0; h<H; h++) {
            y=0;
            for (int wc=0;wc<WC;wc++) {
                y += ( data[ h*WC + wc]) * ( X->data[ n*WC + wc ]);
            }
            result->data[ n*H + h ] = exp(y);
            sum += exp(y); // save Y
        }
        for (int h=0; h<H; h++) {
            result->data[ n*H + h ] = result->data[ n*H + h ]/sum;
        }
    }

};


void tens::BackWX( tens* Eout, tens* dF, tens* eIn, tens* X ) {
    double sum=0;
    int Xn=X->getN(); // number of images
    for (int n=0;n<Xn;n++) { // by images

        for (int w=0;w<W;w++) { //           W = 64 (input size)
            sum=0;
            for (int h=0;h<H;h++) { // H = 10 (output size)
                // prepare Eout
                // sum[] = W[m]   * Ein*dF <-- over n
                sum += (data[ h*W + w ]) * (eIn->data[ n*H + h ]) * (dF->data[n*H + h]);
                data[h*W + w ]=data[h*W + w ] + mu*  (eIn->data[ n*H + h ]) * (dF->data[n*H + h])  * X->data[n*WC + w];
            }
            Eout->data[n*H + w]=sum;
        }
    }
};



void tens::BackSoftmax( tens* Eout, tens* eIn, tens* X ) {
    double sum=0;
    int Xh=X->getH();
    int Xn=X->getN(); // number of images
    for (int n=0;n<Xn;n++) { // by images



        for (int w=0;w<W;w++) { // x[Xh] = 64 (input size)
            sum=0;
            for (int h=0;h<H;h++) { //10
               // prepare Eout
               // sum[] = W[m]   * Ein  <-- over n
               // sum[] = W[i64, 10neu] * Ein[neu10 , n]         <--over neu
               sum += (data[h*WC + w])*(eIn->data[ n*H + h ]);


               //update
               // W[m] = W[m] - ( X[m] * Ein )  <-- over n
               // W[m] = W[i64 , 10neu] - ( X[i64 , n] * Ein[10neo , n] )
               data[h*WC + w]=data[h*WC + w] + mu * eIn->data[n*H + h]* X->data[n*WC + w];
            }
             Eout->data[ n*WC + w ]=sum;
        }
    }
};














double tens::getMax( const double Y[], int len ) {
    double max=Y[0];
    for (int i=1;i<len;i++) {
        if (Y[i]>max) { max=Y[i]; }
    }
    return max;
};


double tens::getSum( const double Y[], int len ) {
    double sum=0.0;
    for (int i=0;i<len;i++) {
        sum+=Y[i];
    }
    return sum;
};

void tens::expAryminusMax(  double Y[], double max ,int len ) {
    for (int i=0;i<len;i++) {
        Y[i]=std::exp(Y[i]-max);
    }
};

void tens::mullAryByValue(  double Y[], double value ,int len ) {
    for (int i=0;i<len;i++) {
        Y[i]=Y[i]/value;
    }
};

void tens::showShape() {
    std::cout<<"N: "<<N<<", H: "<<H<<", W: "<<W<<", C:"<<C<<std::endl;
}


void tens::calculateGradientAtEndSoftmax(tens* S) { // this is Z
    //   [1] - [0.54]
    //   [0] - [0.47]
     for (int i=0;i<NHWC;i++) {
         data[i]= S->data[i] - data[i];
     }
    //for (int i=0;i<NHWC;i++){ data[i]=data[i] -1*S->data[i]; }
    //for (int i=0;i<NHWC;i++){ data[i]= -.3+ S->data[i]; }
}

void tens::getAccuracy(tens* S) { //Z-S
    float max=0; int index; double acc=0;
    for (int n=0;n<N;n++) {
        max=0; index=0;
        for ( int i=0;i<W;i++ ) {
            if (data[ n*HWC + i]>max){ max=data[ n*HWC + i]; index=i; }
        }
        //std::cout<<"?:"<<data[ n*HWC + index*WC] << " : " <<  S->data[ n*HWC + index] << std::endl;
        if ( (S->data[ n*HWC + index]) > 0.8 ) { acc++; }
    }
    std::cout<<"ACC:"<<(acc/N)<<" "<<std::endl;
}

tens* tens::getOneN( int index ) {
    tens* t = new tens(1, H, W, C );
    for (int i=0;i<HWC;i++){ t->data[i]=data[index*HWC + i]; }
    return t;
}
