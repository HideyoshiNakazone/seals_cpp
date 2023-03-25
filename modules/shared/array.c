#include "array.h"


bool equal_array(Array* a, Array* b) {
    if (a == NULL || b == NULL) {
        return false;
    }

    if (a->size != b->size) {
        return false;
    }

    for (int i = 0; i < a->size; i++) {
        if ( fabs(a->data[i] - b->data[i]) > EPSILON) {
            return false;
        }
    }

    return true;
}

bool equal_matrix(Matrix* a, Matrix* b) {
    if (a == NULL || b == NULL) {
        return false;
    }

    if (a->size_x != b->size_x || a->size_y != b->size_y) {
        return false;
    }

    for (int i = 0; i < a->size_x; i++) {
        for (int j = 0; j < a->size_y; j++) {
            if (fabs(a->data[i][j] - b->data[i][j]) > EPSILON) {
                return false;
            }
        }
    }

    return true;
}

Array* to_array(Matrix* matrix) {
    if (matrix->size_y != 1) {
        printf("Matrix must be a column vector to be converted to an array.");
        return NULL;
    }

    Array* array = (Array*) malloc(sizeof(Array));

    array->size = matrix->size_x;
    array->data = allocate_array(array->size);
    
    for (int i = 0; i < array->size; i++) {
        array->data[i] = matrix->data[i][0];
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