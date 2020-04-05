#include "edge.h"

KernelEdges::KernelEdges (void)
{
    total = 4;

    int horizontal[9] = 
    {
        -1, -2, -1, 
         0,  0,  0, 
         1,  2,  1
    };

    int vertical[9] = 
    {
        -1,  0,  1, 
        -2,  0,  2, 
        -1,  0,  1
    };
    
    int horizontal2[25] = 
    {
        -1, -2, -4, -2, -1,
         0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,
         1,  2,  4,  2,  1
    };

    int vertical2[25] =
    {
        -1,  0,  0,  0,  1,
        -2,  0,  0,  0,  2,
        -4,  0,  0,  0,  4,
        -2,  0,  0,  0,  2,
        -1,  0,  0,  0,  1
    };

    vertical3x3.set( vertical, 3 );
    horizontal3x3.set( horizontal, 3 );
    vertical5x5.set( vertical2, 5 );
    horizontal5x5.set( horizontal2, 5 );
}

KernelEdges::~KernelEdges (void){}

void KernelEdges::print (void) const
{
    vertical3x3.print();
    horizontal3x3.print();
    vertical5x5.print();
    horizontal5x5.print();
}
