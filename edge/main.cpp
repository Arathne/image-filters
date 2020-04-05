#include "kernel.h"
#include "iterator.h"
#include "image.h"

#include <iostream>
#include <stdio.h>
#include <string>

#define HEIGHT 1920
#define WIDTH 1080

FILE* src_file;
FILE* out_file;

Image flowerImage(500, 500);

void generateRaw( Kernel current_filter, std::string file_name )
{
    std::cout << file_name << std::endl;
    current_filter.print();
    
    flowerImage.sobel( current_filter, current_filter.getSize() );  
    
    out_file = fopen( file_name.c_str(), "wb" );
    fwrite( flowerImage.output(), 1, 500*500*3, out_file );
    fclose( out_file );
}

int main()
{
    KernelIterator filters;
    
    src_file = fopen( "flower.raw", "rb" );
    flowerImage.setData( src_file );
    fclose(src_file);
    
    filters.first();
    generateRaw( filters.current(), "horizontal3x3.raw" );
    filters.next();
    generateRaw( filters.current(), "vertical3x3.raw" );
    filters.next();
    generateRaw( filters.current(), "horizontal5x5.raw" );
    filters.next();
    generateRaw( filters.current(), "vertical5x5.raw" );
    
    return 0;
}
