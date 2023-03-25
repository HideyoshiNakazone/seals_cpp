#include <stdio.h>
#include <stdlib.h>

#include "array.h"


Array* to_array(Matrix* matrix) {
    if (matrix->size_x != 1) {
        printf("Matrix must be a column vector to be converted to an array.");
        return NULL;
    }

    Array* array = (Array*) malloc(sizeof(Array));

    array->size = matrix->size_y;
    array->data = allocate_array(array->size);
    
    for (int i = 0; i < array->size; i++) {
        array->data[i] = matrix->data[0][i];
    }

    return array;
}

double* allocate_array(int size) {
    return (double*) malloc(size * sizeof(double));
}

double** allocate_matrix(int size_x, int size_y) {
    double** data = (double**) malloc(size_x * sizeof(double*));

    for (int i = 0; i < size_x; i++) {
        data[i] = allocate_array(size_y);
    }

    return data;
}

void free_array(Array** array) {
    free((*array)->data);
    free(*array);

    *array = NULL;
}

void free_matrix(Matrix** matrix) {
    for (int i = 0; i < (*matrix)->size_x; i++) {
        free((*matrix)->data[i]);
    }
    free((*matrix)->data);
    free(*matrix);

    *matrix = NULL;
}