#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <iostream>

class Image
{
    public:
        Image (void);
        Image (unsigned int height, unsigned int width);

    private:
        unsigned int height;
        unsigned int width;
        
        unsigned char* green;
};

#endif
