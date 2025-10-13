#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int const IMGSIZE =1024;

    //printf( "#  --- C++ ---\n+lenx:%i", lenx);
    srand((int)time(0));

    //testLoadAndSave();
    float* C = new float [IMGSIZE];
    for (int i = 0; i < IMGSIZE; i++) {
        C[i] = 0.001f*i;
    }

    float D = 0.0f;
    printf("value: %f, %f\r\n", C[1], C[1023]);




    //-- start
    clock_t before = clock();

    for (int k=0;k<1000;k++){
    for (int j=0;j<1000;j++){
    for (int i = 0; i < IMGSIZE; i++) {
	D+=C[i];
    }
    }
    }
    clock_t duration = clock() - before;
    printf("\r\nduration: %lu [clocks tick], %ld[sek]\r\n", duration, duration/CLOCKS_PER_SEC );

    printf("D:%f \n", D);

}
