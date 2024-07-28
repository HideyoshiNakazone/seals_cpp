#include "matrix.hpp"


template<typename T>
Matrix<T>::Matrix(int size_x, int size_y) {
    this->data = new T*[size_x];

    for (int i = 0; i < size_x; i++) {
        this->data[i] = new T[size_y];
    }

    this->size_x = size_x;
    this->size_y = size_y;
}


template<typename T>
Matrix<T>::Matrix(int size_x, int size_y, T** data) {
    this->data = data;
    this->size_x = size_x;
    this->size_y = size_y;
}


template<typename T>
bool Matrix<T>::equal(Matrix* other) {
    if (other == NULL) {
        return false;
    }

    if (this->size_x != other->size_x || this->size_y != other->size_y) {
        return false;
    }

    for (int i = 0; i < this->size_x; i++) {
        for (int j = 0; j < this->size_y; j++) {
            if (fabs(this->data[i][j] - other->data[i][j]) > EPSILON) {
                return false;
            }
        }
    }

    return true;
}


template<typename T>
Array<T>* Matrix<T>::to_array() {
    if (this->size_y != 1) {
        printf("Matrix must be a column vector to be converted to an array.");
        return NULL;
    }

    Array<T>* array = new Array<T>(this->size_x);

    for (int i = 0; i < array->size; i++) {
        array->data[i] = this->data[i][0];
    }

    return array;
}