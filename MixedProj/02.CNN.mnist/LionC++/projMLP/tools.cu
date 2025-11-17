
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include<cmath>

#include "tens.cpp"

// #include <cuda_runtime.h>
// #include <cudnn.h>


void showImage(const double* ary, int h, int w){
   for (int i=0;i<h;i++){
     for (int j=0;j<w;j++){
        int ii=(int)0+16*ary[i*w+j];
        if (ii==0)
          std::cout <<".";
        else if(ii<=1)
          std::cout <<"+";
        else if(ii<=10)
          std::cout <<"*";
        else
          std::cout <<"#";

     }
     std::cout << std::endl;
   }
}


tens* load_images_asTensor( const std::string& filename, int N, int H, int W, int C ) { // n-images num, h- height, w-width, c-channels
    tens* t = new tens(N,H,W,C);
    int NHWC = N*H*W*C;
    int HWC  = H*W*C;
    int WC   = W*C;

    char* buff = new char[ N*HWC ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 16);
    file.read( reinterpret_cast<char*>(buff), N*HWC );

    for (int n=0;n<N;n++) {
        for (int h=0;h<H;h++){
            for (int w=0;w<W;w++){

                int i= h*W + w;
                double val =  ((unsigned char)buff[n*HWC + i])/256.0;
                t->data[ n*HWC + h*WC + w]=val;
                //t->data[n*HWC + h*W + w]=val;
               /* for ( int c=0;c<C;c++) {
                    int i=r*W + c;
                    double val =  ((unsigned char)buff[n*HWC + i])/256.0;
                    int i= n*HWC + h*WC + w*C + c;
                    double val =  ((unsigned char)buff[i + n*HWC])/256.0;
                    t->data[n*HWC + h*WC + w*C + c]=val;
                } */

            }
        }
    }
    file.close();
    return t;
}


/*
void load_images( double* t, const std::string& filename, int num_images, int rows, int cols) {
    char* buff = new char[ num_images*rows*cols ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 16);
    file.read( reinterpret_cast<char*>(buff), num_images*rows*cols );

    for (int im=0;im<num_images;im++){
       //out[im]=new double[rows*cols];
       for (int r=0;r<rows;r++){
          for (int c=0;c<cols;c++){
            int i=r*cols + c;
            double val =  ((unsigned char)buff[im*rows*cols + i])/256.0;
            out[im][i]= val;
          }
       }
    }
    file.close();
}
*/


tens* load_labels(  const std::string& filename, int num_images, int class_num ) {

    char* buff = new char[ num_images ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 8);
    file.read( reinterpret_cast<char*>(buff), num_images );

    tens* t = new tens(num_images,class_num,1,1);
    //for (int i=0; i<(num_images*class_num); i++){ t->data[ i ]=0.0; }
    for (int n=0;n<num_images;n++){
       int val= (unsigned char) buff[n] *1;
       //std::cout << "VAL:" << val << std::endl;
       t->data[ n*class_num + val ]=1.0;
    }
    file.close();
    return t;
}


void printVec100( double ary[] ) {
    for (int i=0;i<28*28;i++) { std::cout<<" "<<ary[i]; if (i%28==0){std::cout<<std::endl;} }
}
void printVec100( const double ary[] ) {
    for (int i=0;i<28*28;i++) { std::cout<<" "<<ary[i]; } std::cout<<std::endl;
}

void printVec10( double ary[] ) {
    std::cout<<std::endl<<"one-hot: ";
    for (int i=0;i<10;i++) { std::cout<<" ["<<i<<"] "<<ary[i]; }
}





