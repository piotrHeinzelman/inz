//
// Created by john on 16.11.2025.
//

#include "tens.h"

#include <iostream>

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
    if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return;
    data[1*HWC + h*WC + w*C + c]=value;
};

void tens::setPoint(int n, int h, int w, int c, double value) {
    if ( n>N || h>=H || w>=W || c>=C || n<0 || h<0 || w<0 || c<0 ) return;
    data[n*HWC + h*WC + w*C + c]=value;
};

void tens::rand(int min, int max) {
    srand(time(0));
    int delta=max-min;
    for (int i=0;i<NHWC;i++) data[i]=( min+0.001*( std::rand()%(delta*1000) )); //(m*0.5);//m;;
};

tens* tens::addN1( tens* const y) {
    tens* t=new tens( 1, std::max(this->H,y->H), std::max(this->W,y->W), std::max(this->C,y->C) );
    for (int h=0;h<H;h++) {
        for (int w=0;w<W;w++) {
            for (int c=0;c<C;c++) {
                double val=this->getPoint(h,w,c)+y->getPoint(h,w,c);
                t->setPoint( h, w, c, val);
            }
        }
    }
    return t;
}


tens* tens::mulN1( tens* x,  double mul){
    tens* t=new tens( 1, x->H, x->W, x->C );
    for ( int i=0;i<HWC;i++){
        t->data[i]=mul*x->data[i];
    }
    return t;
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
            //std::cout<<std::endl<<"h: "<<h<<std::endl;
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
    int Xh=X->getH();// X size
    double y=0;
    double z=0;
    //std::cout<<Xn<<std::endl;
    //if (result==nullptr) { result = new tens(Xn, W, 1,1); }// W -> W[ij]*F[i]=Y[j] W[hw]*F[h]=Z[h]
    //if (dF==nullptr)     {     dF = new tens(Xn, W, 1,1); } //   [n*HWC + h*WC + w*C + c]

    for (int n=0;n<Xn;n++) {
        for (int w=0;w<W;w++) {
            y=0;
            for (int h=0; h<H; h++) {
                y += data[ w*Xh + h ] * X->data[ n*Xh + h];
            }
            z  = 1.0/(1.0+std::exp(-y));
            result->data[ n*WC + w] = z;        // <- W IS OK !!! (shape change)
                dF->data[ n*WC + w] = z*(1-z); // F'
        }
    }
};



void tens::WXSoftmax( tens* result, /* !! dF=1 !! */ tens* X ) { //H, W, 1   W[H,W,1]  X[H,1,1], result Y[H,1,1]
    int Xn=X->getN();// X images number
    int Xh=X->getH();// X size
    double y=0;
    double max=0;
    double sum=0;
    double* z=new double[W];
    for (int n=0;n<Xn;n++) {
        for (int w=0;w<W;w++) {
            y=0;
            for (int h=0; h<H; h++) {
                y += data[ w*Xh + h ] * X->data[ n*Xh + h];
            }
            z[w] = y; //1.0/(1.0+std::exp(-y));
        }
          double max = getMax( z, W );
          expAryminusMax(z, max,  W );
          double sum = getSum( z, W );
          mullAryByValue( z, sum ,W );

        for (int w=0;w<W;w++) {
            result->data[ n*WC + w] = z[w];
        }
    }
};


void tens::BackWX( tens* Eout, tens* dF, tens* eIn, tens* X ) { //H, W, 1   W[H,W,1]  X[H,1,1], result Y[H,1,1]
    double sum=0;
    int Xh=X->getH();
    int Xn=X->getN(); // number of images
    for (int n=0;n<Xn;n++) { // by images

        for (int i=0;i<Xh;i++) { // x[Xh] = 64 (input size)
            sum=0;
            for (int neu=0;neu<W;neu++) { //10
                // prepare Eout
                // sum[] = W[m]   * Ein  <-- over n
                // sum[] = W[i64, 10neu] * Ein[neu10 , n]         <--over neu
               // std::cout<<(eIn->data[ n*Xh  + i])<<std::endl;
                sum += (data[i*WC + neu])*(eIn->data[ n*Xh   + i ]);

                //update
                // W[m] = W[m] - ( X[m] * Ein )  <-- over n
                // W[m] = W[i64 , 10neu] - ( X[i64 , n] * Ein[10neo , n] )
               data[i*WC + neu]=data[i*WC + neu] - mu*eIn->data[n*W + i]* X->data[n*Xh + i];
            }
            Eout->data[ n*Xh + i ]=sum;
        }
    }
};



void tens::BackSoftmax( tens* Eout, tens* eIn, tens* X ) {
    double sum=0;
    int Xh=X->getH();
    int Xn=X->getN(); // number of images
    for (int n=0;n<Xn;n++) { // by images

        for (int i=0;i<Xh;i++) { // x[Xh] = 64 (input size)
            sum=0;
            for (int neu=0;neu<W;neu++) { //10
               // prepare Eout
               // sum[] = W[m]   * Ein  <-- over n
               // sum[] = W[i64, 10neu] * Ein[neu10 , n]         <--over neu
               sum += (data[i*WC + neu])*(eIn->data[ n*Xh   + i ]);


               //update
               // W[m] = W[m] - ( X[m] * Ein )  <-- over n
               // W[m] = W[i64 , 10neu] - ( X[i64 , n] * Ein[10neo , n] )
               data[i*WC + neu]=data[i*WC + neu] - mu*eIn->data[n*W + i]* X->data[n*H + i];

            }
             Eout->data[ n*H + i ]=sum;
        }
    }
};













/*

tens* tens::WXSigmoid( tens* result, tens* dF,  tens* X ) { // H, W, 1   W[H,W,1]  X[H,1,1], result Y[H,1,1]
    for (int w=0;w<W;w++) {                                 // setRows( int h, int w_start, int w_end, double*ary )
        double y=0;
        for (int h=0; h<this->H; h++) {
            y+=data[ h*W + w ] * X->data[h];
        }
        double z = ( 1.0f/(1.0f + std::exp( -y ) ));
        result->data[w]=z;
            dF->data[w]=z*(1-z);
    }
};
*/
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
    // if correct label out = Z-1
    // else             out = Z
     for (int i=0;i<NHWC;i++){ data[i]= + S->data[i]+ (( S->data[i]-.5)*2)*data[i]  -1*( S->data[i]) ; }
    //for (int i=0;i<NHWC;i++){ data[i]=data[i] -1*S->data[i]; }
    //for (int i=0;i<NHWC;i++){ data[i]= -.3+ S->data[i]; }
}

void tens::getAccuracy(tens* S) { //Z-S
    float max=0; int index; int acc=0;
    for (int n=0;n<N;n++) {
        max=0; index=0;
        for ( int i=0;i<H;i++ ) {
            if (data[ n*HWC + i*WC]>max){ max=data[ n*HWC + i*WC]; index=i; }
        }
        //std::cout<<"?:"<<data[ n*HWC + index*WC] << " : " <<  S->data[ n*HWC + index] << std::endl;
        if ( (S->data[ n*HWC + index]) > 0.8 ) { acc++; }
    }
    std::cout<<"ACC:"<< (100*acc)/N<<"%"<<std::endl;
}