
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include<cmath>
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


void load_images_asTensor( double** out, const std::string& filename, int N, int H, int W, int C ) { // n-images num, h- height, w-width, c-channels
    int HCW = H*C*W;
    int CW  = C*W;

    char* buff = new char[ N*HCW ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 16);
    file.read( reinterpret_cast<char*>(buff), N*HCW );


    for (int n=0;n<N;n++){
        for (int h=0;h<H;h++){
            for (int w=0;w<W;w++){
                for ( int c=0;c<C;c++) {
                    int i= h*CW + w*C + c;
                    double val =  ((unsigned char)buff[i + n*HCW])/256.0;
                    out[n][i]= val;
                }
            }
        }
    }
    file.close();
}



void load_images( double** out, const std::string& filename, int num_images, int rows, int cols) {
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

void load_labels( double** out, const std::string& filename, int num_images, int class_num ) {
    char* buff = new char[ num_images ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 8);
    file.read( reinterpret_cast<char*>(buff), num_images );
    for (int im=0;im<num_images;im++){
       //out[im]=new double[class_num];
       for (int c=0;c<class_num;c++){
            out[im][c]=0.0;
       }
       int val= (unsigned char ) buff[im] *1;
       if (val==10) {val=0;} //else {val++;}
       //std::cout << "Label:" << im << " , val" << val << " !! ";
       out[im][ val ]=1.0;
    }
    file.close();
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



double* extendAry( double* X, int padding, int tensorH, int tensorW, int tensorC ){
    int Hpp=( tensorH+padding+padding );
    int Wpp=( tensorW+padding+padding );
    double* outX = new double [ Hpp * Wpp * tensorC ];
    for (int i=0;i<Hpp * Wpp * tensorC;i++){ outX[i]=0.0; }

    int startOffset=(tensorW + 2*padding + 1 )*padding*tensorC;
    int heightOffset= (2*padding)*tensorC;

    for (int i=0;i<tensorH;i++) {
        for (int j=0;j<tensorC*tensorW;j++) {
            outX[startOffset + i* heightOffset + i*tensorW*tensorC+j] = X[i*tensorW*tensorC+j];
        }
    }
    delete X;
    return outX;
}

void printTensor( double* X, int H, int W, int C) {
    for ( int h=0;h<H;h++) {
        std::cout << std::endl << "** h: " << h <<" **"<< std::endl;
        for (int w=0;w<W;w++) {
            std::cout << "| ";
            for (int c=0;c<C;c++) {
                std::cout << X[ h*W*C + w*C + c] << " ";
            }
            std::cout << " |" << std::endl;
        }
    }
}