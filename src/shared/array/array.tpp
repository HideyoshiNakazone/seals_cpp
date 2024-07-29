#include <stdio.h>
#include <random>

#include "array.hpp"


template<typename T>
Array<T>::Array() {
    this->data = new T[DEFAULT_CAPACITY];
    this->capacity = DEFAULT_CAPACITY;
    this->size = 0;
}

template<typename T>
Array<T>::Array(uint size, T* data) {
    this->data = data;
    this->size = size;
    this->capacity = size;
}

template<typename T>
void Array<T>::push_back(T value) {
    if (this->size == this->capacity) {
        this->resize(this->capacity * 2);
    }

    this->data[this->size] = value;
    this->size++;
}

template<typename T>
bool Array<T>::equal(Array* other) {
    if (other == NULL) {
        return false;
    }

    if (this->size != other->size) {
        return false;
    }

    for (uint i = 0; i < this->size; i++) {
        if (fabs(this->data[i] - other->data[i]) > EPSILON) {
            return false;
        }
    }

    return true;
}

template<typename T>
Array<T>* Array<T>::copy() {
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i];
    }
    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::addByScalar(T scalar) {
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] + scalar;
    }
    
    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::subByScalar(T scalar) {
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] - scalar;
    }
    
    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::mulByScalar(T scalar) {
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] * scalar;
    }
    
    return new Array<T>(this->size, data);
}   

template<typename T>
Array<T>* Array<T>::divByScalar(T scalar) {
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] / scalar;
    }
    
    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::addByArray(Array *other) {
    if (this->size != other->size) {
        return NULL;
    }

    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] + other->data[i];
    }
    
    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::subByArray(Array *other) {
    if (this->size != other->size) {
        return NULL;
    }
    
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] - other->data[i];
    }

    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::mulByArray(Array *other) {
    if (this->size != other->size) {
        return NULL;
    }
    
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] * other->data[i];
    }

    return new Array<T>(this->size, data);
}

template<typename T>
Array<T>* Array<T>::divByArray(Array *other) {
    if (this->size != other->size) {
        return NULL;
    }
    
    T* data = new T[this->size];
    for (uint i = 0; i < this->size; i++) {
        data[i] = this->data[i] / other->data[i];
    }

    return new Array<T>(this->size, data);
}

template<typename T>
bool Array<T>::resize(uint new_size) {
    if (new_size <= this->capacity) {
        return true;
    }
    
    void *data = realloc(this->data, sizeof(T) * new_size);
    if (data == NULL || data != this->data) {
        return false;
    }

    return true;
}