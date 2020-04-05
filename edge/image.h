//must be raw and non-interleaved

#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <iostream>

#include "kernel.h"

class Image
{
    public:
        Image (void);
        Image (unsigned int height, unsigned int width);
        void setData (FILE* file);
        void sobel (Kernel filter, int size);
        unsigned char* output (void);

    private:
        unsigned int height;
        unsigned int width;
        
        unsigned char* data;
        unsigned char* out;

        unsigned char** red;
        unsigned char** green;
        unsigned char** blue;
        unsigned char** gray;
        
        int** edited;
        
        void initialize (void);
        void resetOut (void);
        void sobelCalc (Kernel filter, int row, int col, int size);
        void print (void);
};

#endif
