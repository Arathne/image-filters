#include "kernel.h"
#include "iterator.h"
#include <iostream>

int main()
{
    KernelIterator filters;
    
    for( filters.first(); !filters.isDone(); filters.next() )
    {
        Kernel sobelFilter = filters.current();
    }

    return 0;
}
