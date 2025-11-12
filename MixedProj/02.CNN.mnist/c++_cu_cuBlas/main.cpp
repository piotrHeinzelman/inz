#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

//using namespace std;

void load_images( double* out, const std::string& filename, int num_images, int rows, int cols) {
    char* buff = new char[ num_images*rows*cols ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 16);
    file.read( reinterpret_cast<char*>(buff), num_images*rows*cols );
    for (int im=0;im<num_images;im++){
       for (int r=0;r<rows;r++){
          for (int c=0;c<cols;c++){
            int i=im*rows*cols + r*cols + c;
            //std::cout<<i<<std::endl;
            out[i]= ((unsigned char)buff[i])/256.0;
          }
       }
    }
    file.close();
}

void load_labels( double* out, const std::string& filename, int num_images, int class_num ) {
    char* buff = new char[ num_images ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 8);
    file.read( reinterpret_cast<char*>(buff), num_images );
    for (int im=0;im<num_images;im++){
       for (int c=0;c<class_num;c++){
            int i=im*class_num + c;
            out[i]=0;
       }
       out[im*class_num+buff[im]]=1;
    }
    file.close();
}




int main() {
   int const percent = 1;
   int const class_num=10;
   long const len = percent*100;
   const long CYCLES = 500;

   std::cout << "#  --- C++ ---\n";

   double* X = new double[ len*784*6 ];
   double* Y = new double[ len* class_num*6 ];

   load_images( X,  "/home/john/inz/MixedProj/01.MPL/data/train-images-idx3-ubyte", len*6, 28, 28);
   load_labels( Y,  "/home/john/inz/MixedProj/01.MPL/data/train-labels-idx1-ubyte", len, class_num);
/*
   std::cout << inputFileStreamX.is_open() << "\n"; // Displays 0 because the file is not open

   inputFileStreamX.ignore( 16*sizeof(double) );
   inputFileStreamY.ignore(  8*sizeof(double) );

   inputFileStreamX.read( X, percent * 100 * 784 * 6 * sizeof( double )  );
   inputFileStreamY.read( Y, percent * 100 *   1 * 6 * sizeof( double )  );


   inputFileStreamX.close();
   inputFileStreamY.close();
*/
   for (int i=0;i<28;i++){
     for (int j=0;j<28;j++){
        int ii=(int)0+16*X[i*28+j];
        if (ii==0)
          std::cout <<" ";
        else if(ii<=5)
          std::cout <<"+";
        else if(ii<=10)
          std::cout <<"*";
        else
          std::cout <<"#";

     }
     std::cout << std::endl;
   }

   delete X;
   delete Y;
   return 0;
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

  return 0;
}






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
