#pragma once

#include <vector>
#include <math.h>


#define EPSILON 0.000001


template<class T>
class Array {
    public:
        Array(uint size);
        Array(uint size, T* data);

        ~Array() { 
            delete[] data;
        }

        T* data;
        uint size;
        uint capacity;

        bool equal(Array* other);
};



#include "array.tpp"