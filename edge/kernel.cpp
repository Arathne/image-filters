#include "kernel.h"

Kernel::Kernel (void)
{
    this-> data_ = nullptr;
    this-> size_ = 0;
}

void Kernel::set (int* data, size_t kernel_size)
{
    this-> size_ = kernel_size;
    
    this-> data_ = new int*[size_];
    for(int i = 0; i < size_; i++)
        data_[i] = new int[size_];


    int index = 0;
    for( int r = 0; r < size_; r++ )
    {
        for( int c = 0;  c < size_; c++ )
        {
            this-> data_[r][c] = data[index];
            index++;
        }
    }
}

int Kernel::getData (int row, int col)
{
    if( row >= size_ || col >= size_ )
        throw std::out_of_range( "kernel :: out of bounds" );
    
    return data_[row][col];
}

int Kernel::getSize (void)
{
    return size_;
}

Kernel::~Kernel (void) {}

void Kernel::print (void) const
{
    for( int r = 0; r < size_; r++ )
    {
        for( int c = 0; c < size_; c++ )
        {
            std::cout << data_[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
