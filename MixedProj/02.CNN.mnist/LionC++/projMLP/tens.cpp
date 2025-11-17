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
    if (result==nullptr) { result = new tens(Xn, W, 1,1); }// W -> W[ij]*F[i]=Y[j] W[hw]*F[h]=Z[h]
    if (dF==nullptr)     {    dF = new tens(Xn, W, 1,1); } //   [n*HWC + h*WC + w*C + c]

    for (int n=0;n<Xn;n++) {

        for (int w=0;w<W;w++) {
            y=0;
            for (int h=0; h<H; h++) {
                y += data[ n*HWC+ h*W + w ] * X->data[ n*Xh*WC + h];
            }
            z  = 1.0/(1.0+std::exp(-y));
            result->data[ n*WC + w]= z;        // <- W IS OK !!! (shape change)
                dF->data[ n*WC + w]= z*(1-z); // F'
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
