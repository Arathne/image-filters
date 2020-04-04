#include "iterator.h"

KernelIterator::KernelIterator (void)
{
    kernels_ = new Kernel[ edge.total ];
    current_ = 0;

    kernels_[0] = edge.horizontal3x3;
    kernels_[1] = edge.vertical3x3;
    kernels_[2] = edge.horizontal5x5;
    kernels_[3] = edge.vertical5x5;
}


KernelIterator::~KernelIterator (void)
{
    delete[] kernels_;
}

void KernelIterator::first()
{
    current_ = 0;
}

void KernelIterator::next (void)
{
    current_++;
}

bool KernelIterator::isDone (void)
{
    bool done = false;
    
    if( current_ >= edge.total )
        done = true;

    return done;
}

Kernel KernelIterator::current (void)
{
    Kernel output;
    
    if( current_ < edge.total )
        output = *( kernels_ + current_ );

    return output;
}


