#pragma once

#include <stdexcept>
#include <vector>
#include <math.h>


#define EPSILON 0.000001
#define DEFAULT_CAPACITY 100


template<class T>
class Array {
    public:
        Array();
        Array(uint size, T* data);

        ~Array() { 
            delete[] this->data;
        }

        uint getSize() { return size; }

        T at(uint index) const {
            if (index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        void push_back(T value);

        bool equal(Array* other);

        Array<T>* copy();

        Array<T>* addByScalar(T scalar);

        Array<T>* subByScalar(T scalar);

        Array<T>* mulByScalar(T scalar);

        Array<T>* divByScalar(T scalar);

        Array<T>* addByArray(Array *other);

        Array<T>* subByArray(Array *other);

        Array<T>* mulByArray(Array *other);

        Array<T>* divByArray(Array *other);

        static Array<T>* ofZeros(uint size) {
            double *data = new double[size];
            for (uint i = 0; i < size; i++) {
                data[i] = 0;
            }
            return new Array<T>(size, data);
        }

        static Array<T>* ofOnes(uint size) {
            double *data = new double[size];
            for (uint i = 0; i < size; i++) {
                data[i] = 1;
            }
            return new Array<T>(size, data);
        }

    private:
        T* data;
        uint size;
        uint capacity;

        bool resize(uint new_size);

};



#include "array.tpp"