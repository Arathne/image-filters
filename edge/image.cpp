#include "image.h"

Image::Image (void)
{
    this-> height = 1920;
    this-> width = 1080;
    initialize();
}

Image::Image (unsigned int height, unsigned int width)
{
    this-> height = height;
    this-> width = width;
    initialize();
}

void Image::initialize (void)
{
    data = new unsigned char[ height * width * 3 ];
    out = new unsigned char[ height * width * 3 ];
    
    red = new unsigned char*[height];
    green = new unsigned char*[height];
    blue = new unsigned char*[height];
    gray = new unsigned char*[height];
    
    for( int r = 0; r < height; r++ )
    {
        red[r] = new unsigned char[width];
        green[r] = new unsigned char[width];
        blue[r] = new unsigned char[width];
        gray[r] = new unsigned char[width];
    }
}


void Image::setData (FILE* file)
{
    fread( data, 1, height*width*3, file );
    
    int index = 0;
    for( int r = 0; r < height; r++ )
    {
        for( int c = 0; c < width; c++ )
        {
            red[r][c] = data[index];
            green[r][c] = data[index + (height*width)];
            blue[r][c] = data[index + (height*width*2)];
            gray[r][c] = (red[r][c] + green[r][c] + blue[r][c]) / 3;    
            index++;
        }
    }
}

void Image::resetOut (void)
{
    for( int i = 0; i < height*width*3; i++ )
    {
        out[i] = 0;
    }
}

void Image::print (void)
{
    /*for( int r = 0; r < height; r++ )
    {
        for( int c = 0; c < width; c++ )
        {
            std::cout << (int) red[r][c] << std::endl;
        }
    }*/
}





















/*unsigned char* Image::getRed (void)
{
    resetOut();

    int index = 0;
    for( int r = 0; r < height; r++ )
    {
        for( int c = 0; c < width; c++ )
        {
            unsigned char color = gray[r][c];
            out[index] = color;
            out[index+(height*width)] = color;
            out[index+(height*width*2)] = color;
            index++;
        }
    }
    
    return out;
}*/
