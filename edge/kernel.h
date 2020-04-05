#ifndef KERNEL_H
#define KERNEL_H

#include <cstring>
#include <iostream>
#include <stdexcept>

class Kernel
{
    public:
        Kernel (void);
        ~Kernel (void);
        void set (int* data, size_t kernel_size);
        void print (void) const;
        int getData (int row, int col);
        int getSize (void);

    private:
        int** data_;
        size_t size_;
};

#endif
