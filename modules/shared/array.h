#pragma once

#include <vector>
#include <math.h>


#define EPSILON 0.000001


template<class T>
class Array {
    public:
        Array(int size);
        Array(int size, T* data);

        ~Array() { 
            delete[] data;
        }

        T* data;
        int size;

        bool equal(Array* other);
};


template<class T>
class Matrix {
    public:
        Matrix(int size_x, int size_y);
        Matrix(int size_x, int size_y, T** data);

        ~Matrix() {
            for (int i = 0; i < this->size_x; i++) {
                delete[] data[i];
            }
            delete[] data;
        }

        T **data;
        int size_x;
        int size_y;

        bool equal(Matrix* other);

        Array<T>* to_array();
};


#include "array.tpp"