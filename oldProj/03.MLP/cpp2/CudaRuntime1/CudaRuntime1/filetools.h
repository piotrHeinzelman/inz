#ifndef FILETOOLS_H
#define FILETOOLS_H

void loadXandY(float** X, uint8_t* Y, int percent, int IMGSIZE, bool train);

void saveFloatsToFile(char* filename, float* floats, int size);
void loadFloatsToFile(char* filename, float* floats, int arySize);

void testLoadAndSave();




#endif // FILETOOLS_H