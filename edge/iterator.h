#ifndef KERNEL_ITERATOR_H
#define KERNEL_ITERATOR_H

#include "edge.h"
#include "kernel.h"

class KernelIterator
{
    public:
        KernelIterator (void);
        ~KernelIterator (void);
        void first (void);
        void next (void);
        bool isDone (void);
        Kernel current (void);

    private:
        KernelEdges edge;
        Kernel* kernels_;
        int current_;
};

#endif
