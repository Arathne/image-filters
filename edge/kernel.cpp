#include "kernel.h"

Kernel::Kernel (void)
{
    this-> data_ = nullptr;
    this-> size_ = 0;
}

void Kernel::set (int* data, size_t size)
{
    this-> size_ = size;
    this-> data_ = new int[size_];

    for( int i = 0; i < size_; i++ )
    {
        this-> data_[i] = data[i];
    }
}

Kernel::~Kernel (void) {}

int & Kernel::operator [] (size_t index)
{
    if( index >= size_ )
        throw std::out_of_range( "kernel :: index out of bounds" );

    return *( data_+index );
}

void Kernel::print (void) const
{
    for( int i = 0; i < size_; i++ )
        std::cout << data_[i] << " ";

    std::cout << std::endl;
}
