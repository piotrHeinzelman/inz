#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;


int main() {

   int const percent = 80;
   long const len = percent*100;
   const long CYCLES = 500;


  cout << "#  --- C++ ---\n";


   double X[ len*784*6 ];
   double Y[ len*  1*6 ];
   ifstream  inputFileStreamX( "data/train-images-idx3-ubyte" , ios::in | ios::binary); // 16, percent, 6)
   ifstream  inputFileStreamY( "data/train-labels-idx1-ubyte" , ios::in | ios::binary); //  8, percent, 6)


   inputFileStreamX.ignore( 16*sizeof(double) );
   inputFileStreamY.ignore(  8*sizeof(double) );


   inputFileStreamX.read( (char*) &X, percent * 100 * 784 * 6 * sizeof( double )  );
   inputFileStreamY.read( (char*) &Y, percent * 100 *   1 * 6 * sizeof( double )  );


   inputFileStreamX.close();
   inputFileStreamY.close();

   cout << X;

   exit(0);


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
