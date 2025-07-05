
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