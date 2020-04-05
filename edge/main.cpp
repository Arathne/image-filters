#include "kernel.h"
#include "iterator.h"
#include "image.h"

#include <iostream>
#include <stdio.h>

#define HEIGHT 1920
#define WIDTH 1080

FILE* src_file;
FILE* out_file;

int main()
{
    src_file = fopen( "flower.raw", "rb" );
    Image image(500, 500);   
    image.setData( src_file );
    fclose(src_file);
    
    /*out_file = fopen( "flowerGRAY.raw", "wb" );
    fwrite( image.getRed(), 1, 500*500*3, out_file );
    fclose( out_file )*/

    KernelIterator filters;
    
    for( filters.first(); !filters.isDone(); filters.next() )
    {
        Kernel sobelFilter = filters.current();
    }

    return 0;
}
