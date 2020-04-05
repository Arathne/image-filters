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
    edited = new int*[height];
    
    for( int r = 0; r < height; r++ )
    {
        red[r] = new unsigned char[width];
        green[r] = new unsigned char[width];
        blue[r] = new unsigned char[width];
        gray[r] = new unsigned char[width];
        edited[r] = new int[width];
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
        out[i] = 127;
    }
}

void Image::sobel (Kernel filter, int size)
{
    for( int r = (size/2); r < height-(size/2); r++ )
    {
        for( int c = (size/2); c < width-(size/2); c++ )
        {
            
            sobelCalc( filter, r, c, size );
        }
    }
}

void Image::sobelCalc ( Kernel filter, int row, int col, int size )
{
    int upperBound = size/2;
    int lowerBound = upperBound*-1;
    int previous = 0;
    for( int i = lowerBound; i <= upperBound; i++ )
    {
        for( int j = lowerBound; j <= upperBound; j++ )
        {
            edited[row][col] = (gray[row+i][col+j] * filter.getData(i+upperBound,j+upperBound)) + previous;
            previous = edited[row][col];
        }
    }
}

void Image::print (void)
{
    for( int r = 0; r <= 5; r++ )
    {
        for( int c = 0; c <= 5; c++ )
        {
            std::cout << edited[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

unsigned char* Image::output (void)
{
    resetOut();

    int index = 0;
    for( int r = 0; r < height; r++ )
    {
        for( int c = 0; c < width; c++ )
        {
            unsigned char color = (char) edited[r][c] + 127;
            out[index] = color;
            out[index+(height*width)] = color;
            out[index+(height*width*2)] = color;
            index++;
        }
    }
    
    return out;
}
