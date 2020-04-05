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
    



    KernelIterator filters;
    
    for( filters.first(); !filters.isDone(); filters.next() )
    {
        Kernel sobelFilter = filters.current();
    }

    return 0;
}
