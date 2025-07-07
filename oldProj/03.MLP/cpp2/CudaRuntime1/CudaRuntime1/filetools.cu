
void saveFloatsToFile(char* filename, float* floats, int arySize) {
    FILE* fb;
    fb = fopen( (char*) filename, "wb");
    for (int i = 0; i < arySize; i++) {
        fwrite(&floats[i], sizeof(float), 1, fb);
    }
    fclose(fb);
}


void loadFloatsToFile(char* filename, float* floats, int arySize) {
    FILE* fb;
    fb = fopen((char*)filename, "rb");
    for (int i = 0; i < arySize; i++) {
        fread(&floats[i], sizeof(float), 1, fb);
    }
    fclose(fb);
}

void testLoadAndSave() {
    float* Test = new float[10];
        float* Check = new float[10];
        Test[0] = -.5f;
        Test[1] = 17.17f;
        Test[2] = .00000001f;
        Test[3] = 125.0f;
        Test[4] = -9999.0f;
        Test[5] = -99.0005f;

        saveFloatsToFile((char*)"testFile", Test, 5);
        loadFloatsToFile((char*)"testFile", Check, 5);
        printf("\n IN: %f : %f : %f : %f : %f ", Test[0], Test[1], Test[2], Test[3], Test[4]);
        printf("\nOUT: %f : %f : %f : %f : %f ", Check[0], Check[1], Check[2], Check[3], Check[4]);
}



void loadXandY(float** X, uint8_t* S, int percent, int IMGSIZE, bool train) {
    using namespace std;
   
    int len = train ? 6 : 1;
    len = len * 100 * percent;

    //X = new float* [len];
    for (int i = 0; i < len; i++) {
        X[i] = new float[IMGSIZE];
    }
    //S = new uint8_t[len];

    ifstream  inputFileStreamX("../../../data/train-images-idx3-ubyte", ios::in | ios::binary); // 16, percent, 6)
    ifstream  inputFileStreamY("../../../data/train-labels-idx1-ubyte", ios::in | ios::binary); //  8, percent, 6)


    inputFileStreamX.ignore(16 * sizeof(uint8_t));
    inputFileStreamY.ignore(8 * sizeof(uint8_t));
    uint8_t* tmp = new uint8_t[784];
    for (int i = 0; i < len; i++) {
        inputFileStreamX.read((char*)tmp, 784 * sizeof(char));
        for (int j = 0; j < 784; j++) {
            X[i][j] = tmp[j] / 255.0f;
        }
        inputFileStreamY.read((char*)&S[i], sizeof(char));
    }

    inputFileStreamX.close();
    inputFileStreamY.close();
}

