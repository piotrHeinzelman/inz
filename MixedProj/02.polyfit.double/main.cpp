// hello.cpp
#include <iostream>
#include <ctime>
#include <fstream>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;


int main() {

const string NAME = "20";
int           len = 20;
const long CYCLES = 1000;
string fileName="datax"+NAME+".bin";


struct dirent * file;
DIR* dirp = opendir("data");
//while ( (file = readdir(dirp)) != NULL ){
//    if ( fileName.compare(   file->d_name ) != 0) { continue; }
    
    ifstream inputFileStream( "data/" + fileName , ios::in | ios::binary);
    
     std::istreambuf_iterator<char>(ifstream);
    
    
    //ifstream.seekg (0, ios::end);
    //len = is.tellg();
    //cout << "Size: " << len << " bytes";
    


    
    
//    }
//closedir( dirp );

  cout << "--- C++  app start: ---\r\n";



//   int len = 
   double X[20];
   ifstream inputFileStream( "data/" + fileName , ios::in | ios::binary);
//   cout << "\r\n\r\n" << ifstream;
   
    cout << "File data is\n";
    for (int i=0; i<20; i++) {
        inputFileStream.read( (char*) &X[i], sizeof( double ));
    }

    inputFileStream.close();


    printf( " %E %E %E\r\n", X[0], X[1], X[2]);


//-- start 
  clock_t before = clock();

  
  int k = 0;
  for (int i = 0; i < 100000; i++) {
    k += i;
  }
  
  
  clock_t duration = clock() - before;
  cout << "duration: " << (float)duration / CLOCKS_PER_SEC << " [sek.]\r\n \r\n";
  cout << "X[" << NAME << "] * " << CYCLES << "\r\n\r\n";
  

  return 0;
}






/*

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
