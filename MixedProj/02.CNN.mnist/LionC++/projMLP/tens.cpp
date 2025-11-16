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
    return data[ h*C*W + w*C +c ];
};


void tens::setPoint(int h, int w, int c, double value) {
    data[ h*C*W + w*C +c ]=value;
};

double* tens::getRows( int h, int w_start, int w_end ) {
    return data+( h*W + w_start);
};

void tens::setRows( int h, int w_start, int w_end, double*ary ) {

};

void tens::loadFrom(double *buff) {
};


void tens::myPrint() {
    for (int h=0;h<H;h++) {
        std::cout<<"h: "<<h<<std::endl;
        for (int w=0;w<W;w++) {
            std::cout<<" | ";
            for (int c=0;c<C;c++) {
                std::cout << getPoint(h,w,c);
            }
            std::cout<<" | "<<std::endl;
        }
    }
};
