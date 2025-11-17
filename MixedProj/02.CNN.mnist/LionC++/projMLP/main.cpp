// https://forums.developer.nvidia.com/t/how-use-the-cudnn-graph-api-for-do-a-convolution/321806
// https://hpc.pku.edu.cn/docs/20170830182053891231.pdf
// https://www.youtube.com/watch?v=GPBeiKYkuZE
// https://docs.nvidia.com/deeplearning/cudnn/archives/cudnn-892/pdf/cuDNN-Developer-Guide.pdf
// https://docs.nvidia.com/deeplearning/cudnn/backend/v9.15.0/api/cudnn-cnn-library.html
// https://docs.nvidia.com/deeplearning/cudnn/backend/v9.15.0/api/cudnn-graph-library.html#cudnncreate
//
// run:
// nvcc -lcuda -lcublas -lcudnn *.cu -o CNN
//
// echo 'g++ main.cpp -o CNN'
// nvcc main.cpp  -lcuda -lcublas -lcudnn -o CNN



#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>

#include "tools.cu"
#include "Layer.h"
#include "NNet.h"
#include "tens.h"


//#include <cuda_runtime.h>
//#include <cudnn.h>
//#include <cublas.h>
//#include <cuda.h>


// notation NHWC = first iteration by Channel (RGB), next by width (ABC), next by high (012) lastly by image numger
//    R       G       B
// 0 ***   0 ***   0 ***    <-like chess
// 1 ***   1 ***   1 ***
// 2 ***   2 ***   2 ***
//   abc     abc     abc
//
//   0   1   2   3   4   5   6   7   8   9
//  Ra0 Ga0 Ba0 Rb0 Gb0 Bb0 Rc0 Gc0 Bc0 R...
//
// image i = i*HWC
//
// w-th row in image start At:  i*HWC + w*HC
//
// h-th pix in row   start At:  i*HWC + w*HC + h*C
//
// value of channel = R: start of pix, G: start +1, B: start +2
//

//
//     for i=0;i<I
//       for h=0; h<H
//         for w=0; w<W
//           for c=0; c<C




int main() {
   int const percent = 1; //80
   long const len = percent*600;
   int const class_num=10;
   int layer_num=2;
   const long epochs = 1; //500



 //  load_images( X,  "/home/john/inz/MixedProj/01.MPL/data/train-images-idx3-ubyte", len, 28, 28);
 //  load_labels( Y,  "/home/john/inz/MixedProj/01.MPL/data/train-labels-idx1-ubyte", len, class_num);

    int height=28, width=28, channel=1;


    tens** XT = new tens*[len];
    double** Y = new double*[len];
    load_images_asTensor( XT, "../../../01.MPL/data/train-images-idx3-ubyte", len, height, width, channel ); // int N, int H, int W, int C )
    //load_images( X,  "../../../01.MPL/data/train-images-idx3-ubyte", len, 28, 28);
     load_labels( Y,  "../../../01.MPL/data/train-labels-idx1-ubyte", len, class_num);

    double* row=new double[9]{1,2,3,4,5,6,7,8,9};
    tens* t1=new tens(3,1,1); t1->setRows(2,0,0,row);
    tens* t2=new tens(1,3,1); t2->setRows(0,0,0,row);
    tens* t3 = t1->add(t2);
    //      t1->setRows( 0, 0, 1, row ); //int h, int w_start, int w_end, double*ary
          t3->myPrint();

    //tens* t=XT[0];
    //      t->myPrint();

    return 0;
}


/*

    std::cout << "#  --- start main ---\n";
    int n = 2;
    int m = 3;

    double* X = new double[m]{ 0.2, -0.3, 0.1 };
    double* Z = new double[n];
    double* S = new double[m]{ 1.0, 0.0 };

    //Layer* lay = new Layer( PERCEPTRON_SIGMOID, n, m);
    Layer* lay = new Layer( PERCEPTRON_SOFTMAX_MULTICLASS, n, m);
           lay->Forward( Z, X );// X

    double* eIn = new double[n];
    for (int j=0;j<n;j++) {
//        std::cout<<"Z["<<j<<"]:"<<Z[j]<< "  eIn[" << j << "]: "<< Z[j] << std::endl;
        eIn[j]=0.4*Z[j] ;
//        std::cout<<"Z["<<j<<"]:"<<Z[j]<< "  eIn["<<j<<"]: " << eIn[j] << std::endl;
    }
    double* eOut=new double[n];
           lay->Backward(eOut, eIn);


    std::cout << "CrossEntropy:" << (double)lay->crossEntropyMulticlassError(Z, S) << std::endl;

   if ( false ) { // load images from file
   std::cout << "#  --- C++ ---\n";

   double* X = new double[ len*784*6 ];
   double* Y = new double[ len* class_num*6 ];

   load_images( X,  "/home/john/inz/MixedProj/01.MPL/data/train-images-idx3-ubyte", len*6, 28, 28);
   load_labels( Y,  "/home/john/inz/MixedProj/01.MPL/data/train-labels-idx1-ubyte", len, class_num);

   showImage(X,28,28);
   showImage(Y,28,10);

   delete X;
   delete Y;
   }


   if (false){ // ************* NVIDIA REQUIERD !
/*
    cudaSetDevice(0); // use GPU0
    int device;
    struct cudaDeviceProp devProp;
    cudaGetDevice(&device);
    cudaGetDeviceProperties(&devProp, device);
    std::cout << "Compute capability:" << devProp.major << "." << devProp.minor << std::endl;

    cudnnHandle_t handle_;
    cudnnCreate(&handle_);
    std::cout << "Created cuDNN handle" << std::endl;

    // create the tensor descriptor
    cudnnDataType_t dtype = CUDNN_DATA_FLOAT;
    cudnnTensorFormat_t format = CUDNN_TENSOR_NCHW;
    int n = 1, c = 1, h = 1, w = 10;
    int NUM_ELEMENTS = n*c*h*w;
    cudnnTensorDescriptor_t x_desc;
    cudnnCreateTensorDescriptor(&x_desc);
    cudnnSetTensor4dDescriptor(x_desc, format, dtype, n, c, h, w);

    // create the tensor
    float *x;
    cudaMallocManaged(&x, NUM_ELEMENTS * sizeof(float));
    for(int i=0;i<NUM_ELEMENTS;i++) x[i] = i * 1.00f;
    std::cout << "Original array: ";
    for(int i=0;i<NUM_ELEMENTS;i++) std::cout << x[i] << " ";

    // create activation function descriptor
    float alpha[1] = {1};
    float beta[1] = {0.0};
    cudnnActivationDescriptor_t sigmoid_activation;
    cudnnActivationMode_t mode = CUDNN_ACTIVATION_SIGMOID;
    cudnnNanPropagation_t prop = CUDNN_NOT_PROPAGATE_NAN;
    cudnnCreateActivationDescriptor(&sigmoid_activation);
    cudnnSetActivationDescriptor(sigmoid_activation, mode, prop, 0.0f);

    cudnnActivationForward(
        handle_,
        sigmoid_activation,
        alpha,
        x_desc,
        x,
        beta,
        x_desc,
        x
    );

    cudnnDestroy(handle_);
    std::cout << std::endl << "Destroyed cuDNN handle." << std::endl;
    std::cout << "New array: ";
    for(int i=0;i<NUM_ELEMENTS;i++) std::cout << x[i] << " ";
    std::cout << std::endl;
    cudaFree(x);
//    return 0;
*/


/*

//-- start
  clock_t before = clock();

   double w1=0.0;
   double w0=0.0;

   double xsr=0.0;
   double ysr=0.0;


  for (int c = 0; c < CYCLES; c++) {

          xsr = 0.0;
          ysr = 0.0;
          w1  = 0.0;
          w0  = 0.0;


      for ( int i=0; i<len; i++ ){
         xsr +=  X[i];
         ysr +=  Y[i];
      }

   xsr=xsr / len;
   ysr=ysr / len;


   double sumTop=0.0;
   double sumBottom=0.0;

      for ( int i=0;i<len;i++ ){ //  xtmp = X[i]-sr ! ;
       sumTop   += ((X[i]-xsr)*(Y[i]-ysr));
      sumBottom += ((X[i]-xsr)*(X[i]-xsr));
      }
      w1 = sumTop / sumBottom;
      w0 = ysr -(w1 * xsr) ;
  }

  clock_t duration = clock() - before;
  cout << "#  X[" << percent << "] * " << CYCLES << "\n";
  cout << "#  time: " << (float)duration / CLOCKS_PER_SEC << " [sek.],  w0: " << w1 << ", w1: " << w0 << "\n";
  cout << "\nc[]=" << (float)duration / CLOCKS_PER_SEC << "\n" ;

*/






/*

//   printf( " %E %E %E\r\n", X[0], X[1], X[2]);
//   printf( " %E %E %E\r\n", Y[0], Y[1], Y[2]);
len = strlen(name);
dirp = opendir(".");
while ((dp = readdir(dirp)) != NULL)
        if (dp->d_namlen == len && !strcmp(dp->d_name, name)) {
                (void)closedir(dirp);
                return FOUND;
        }
(void)closedir(dirp);
return NOT_FOUND;

*/




//https://www.w3schools.com/c/c_ref_stdlib.php
/*

    FILE *f;
    f = fopen("mainfinal.c" , "r");
    fseek(f, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(f);
    printf("%ld\n", len);
    fclose(f);
*/



//   while ( (file = readdir(dirp)) != NULL ){
//      if ( fileName.compare(   file->d_name ) != 0) { continue; }
//           file->seekg(0, ios::end);
//   ifstream inputFileStream( "data/" + fileName , ios::in | ios::binary );

   //ifstream.seekg (0, ios::end);
   //len = is.tellg();
    //cout << "Size: " << len << " bytes";


//    }
//closedir( dirp );


/*


epochs = 100

num_classes = 10


def readFileX ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    data=np.fromfile( fileName, np.uint8, percent*100*784*multi, '', offset )
    data=data.reshape(percent*100*multi, 784)
    data=(data/255)
    file.close()
    return data

def readFileY ( fileName , offset, percent, multi ):
    file=open( fileName, 'rb' )
    file.read( offset )
    len=percent*100*multi
    data=np.fromfile( fileName, np.uint8, len, '', offset )
    file.close()
    return data



trainX = readFileX ('data/train-images-idx3-ubyte', 16, percent ,6 )
trainY = readFileY ('data/train-labels-idx1-ubyte', 8, percent, 6 )
testX = readFileX ('data/t10k-images-idx3-ubyte', 16, percent, 1  )
testY = readFileY ('data/t10k-labels-idx1-ubyte', 8, percent, 1 )


trainX = trainX.astype("float32") # / 255
testX = testX.astype("float32") # / 255
trainX = trainX.reshape(6*percent*100, 784).astype("float32") / 255
testX = testX.reshape(1*percent*100, 784).astype("float32") / 255



model = tf.keras.models.Sequential([
  tf.keras.layers.Input(shape=(784,)),
  tf.keras.layers.Dense(64, activation='sigmoid'),
  tf.keras.layers.Dense(64, activation='sigmoid'),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation='softmax')
])

model.compile(optimizer='adam',
  loss='sparse_categorical_crossentropy',
  metrics=['accuracy'])

start=time.time()


with tf.device('/device:GPU:0'):
   model.fit(trainX, trainY, epochs=epochs, verbose=0)

end=time.time()
d=end-start

clear_session()


print("# Python Tensorflow Time: " , d)

*/

/*

#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace Eigen;

int read_int(std::ifstream& stream) {
    unsigned char bytes[4];
    stream.read(reinterpret_cast<char*>(bytes), 4);
    return (int(bytes[0]) << 24) | (int(bytes[1]) << 16) | (int(bytes[2]) << 8) | int(bytes[3]);
}

MatrixXd load_mnist_images(const std::string& filename, int& num_images, int& rows, int& cols) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) throw std::runtime_error("Cannot open image file!");

    int magic = read_int(file);
    num_images = read_int(file);
    rows = read_int(file);
    cols = read_int(file);

    MatrixXd images(num_images, rows * cols);

    for (int i = 0; i < num_images; ++i) {
        for (int j = 0; j < rows * cols; ++j) {
            unsigned char pixel = 0;
            file.read(reinterpret_cast<char*>(&pixel), 1);
            images(i, j) = static_cast<double>(pixel) / 255.0; // normalize
        }
    }

    return images;
}

VectorXd load_mnist_labels(const std::string& filename, int& num_labels) {

    return labels;
}

//one hot encode labels
MatrixXd toOneHot(VectorXd& labels, int num_labels){
    MatrixXd one_hot {MatrixXd::Zero(labels.rows(), num_labels)};
    for (std::size_t i {}; i<labels.rows(); ++i){
        one_hot(i, static_cast<int>(labels(i))) = 1.0;
    }
    return one_hot;
}
*/
