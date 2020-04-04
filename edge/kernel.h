#ifndef KERNEL_H
#define KERNEL_H

#include <cstring>
#include <iostream>
#include <stdexcept>

class Kernel
{
    public:
        Kernel (void);
        Kernel (int* data, size_t size);
        ~Kernel (void);
        void print (void) const;
        int & operator [] (size_t index);

    private:
        int* data_;
        size_t size_;
};

#endif
