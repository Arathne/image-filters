#ifndef EDGE_H
#define EDGE_H

#include "kernel.h"
#include <iostream>

class KernelEdges
{
    friend class KernelIterator;

    private:
        Kernel vertical3x3;
        Kernel horizontal3x3;
        Kernel vertical5x5;
        Kernel horizontal5x5;
        int total;

    public:
        KernelEdges (void); 
        ~KernelEdges (void);
        void print (void) const;
};

#endif
