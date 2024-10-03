#include <iostream>
#include <ctime>
#include <fstream>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;


int main() {

   const string NAME = "4M";
   int           len = 500000;
   const long CYCLES = 1000;
   string fileName=""+NAME+".bin";


  cout << "--- C++  app start: ---\n";


   double X[ len ];
   double Y[ len ];
   ifstream  inputFileStreamX( "data/datax" + fileName , ios::in | ios::binary);
   ifstream  inputFileStreamY( "data/datay" + fileName , ios::in | ios::binary);

   for (int i=0; i<len; i++) {
        inputFileStreamX.read( (char*)  &X[i], sizeof( double ));
        inputFileStreamY.read( (char*) &Y[i], sizeof( double ));
   }

   inputFileStreamX.close();
   inputFileStreamY.close();


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
  cout << "duration: " << (float)duration / CLOCKS_PER_SEC << " [sek.]\n";
  cout << "X[" << NAME << "] * " << CYCLES << "\n";
  cout << "w0: " << w1 << ", w1: " << w0 << "\n\n";


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
