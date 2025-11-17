//
// Created by john on 16.11.2025.
//

#include "tens.h"

#include <iostream>

//int H, W, C;
//double* data;
//  data = new double[H*W*C];

int tens::getH(){ return this->H; };
int tens::getW(){ return this->W; };
int tens::getC(){ return this->C; };

double tens::getPoint( int h, int w, int c) {
    if (h<H && w<W && c<C)
       return data[ h*C*W + w*C +c ];
    else
        return 0;
};


void tens::setPoint(int h, int w, int c, double value) {
    data[ h*C*W + w*C +c ]=value;
};

double* tens::getRows( int h, int w_start, int w_end ) {
    return data+( h*W + w_start);
};

void tens::setRows( int h, int w_start, int w_end, double*ary ) {
    int start=h*W*C + w_start*C ;
    for (int i=0;i<(w_end+1)*C;i++) {
           data[start+i]=ary[i];
        }
};



tens* tens::add( tens* const y) {
    tens* t=new tens( std::max(this->H,y->H), std::max(this->W,y->W), std::max(this->C,y->C) );
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

tens* tens::mul( tens* x,  double mul){
    tens* t=new tens( x->H, x->W, x->C );
    for ( int i=0;i<(x->H*x->W*x->C);i++){
        t->data[i]=mul*x->data[i];
    }
    return t;
}



void tens::myPrint() {
    for (int h=0;h<H;h++) {
        std::cout<<"h: "<<h<<std::endl;
        for (int w=0;w<W;w++) {
            std::cout<<" | ";
            for (int c=0;c<C;c++) {
                std::cout << getPoint(h,w,c) <<" ";
            }
            std::cout<<" | "<<std::endl;
        }
    }
};
