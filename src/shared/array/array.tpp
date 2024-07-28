#include "array.hpp"


template<typename T>
Array<T>::Array(uint size) {
    data = new T[size];
}

template<typename T>
Array<T>::Array(uint size, T* data) {
    this->data = data;
    this->size = size;
}

template<typename T>
bool Array<T>::equal(Array* other) {
    if (other == NULL) {
        return false;
    }

    if (this->size != other->size) {
        return false;
    }

    for (int i = 0; i < this->size; i++) {
        if (fabs(this->data[i] - other->data[i]) > EPSILON) {
            return false;
        }
    }

    return true;
}