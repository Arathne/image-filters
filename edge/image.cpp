#include "image.h"

Image::Image (void)
{
    this-> height = 1920;
    this-> width = 1080;
}

Image::Image (unsigned int height, unsigned int width)
{
    this-> height = height;
    this-> width = width;
}
