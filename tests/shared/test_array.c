#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../modules/shared/array.h"


bool test_matrix_equal() {
    Matrix* a = (Matrix*) malloc(sizeof(Matrix));

    a->size_x = 2;
    a->size_y = 2;

    a->data = allocate_matrix(a->size_x, a->size_y);
    a->data[0][0] = 1.;
    a->data[0][1] = 1.;
    a->data[1][0] = 1.;
    a->data[1][1] = 1.;

    Matrix* b = (Matrix*) malloc(sizeof(Matrix));
    b->size_x = 2;
    b->size_y = 2;

    b->data = allocate_matrix(b->size_x, b->size_y);
    b->data[0][0] = 1.;
    b->data[0][1] = 1.;
    b->data[1][0] = 1.;
    b->data[1][1] = 1.;

    return equal_matrix(a, b);
}

bool test_to_array() {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));

    matrix->size_x = 1;
    matrix->size_y = 1;

    matrix->data = allocate_matrix(matrix->size_x, matrix->size_y);

    matrix->data[0][0] = 0.;

    Array* array = to_array(matrix);

    if (array->data[0] != 0.) {
        return false;
    }

    return true;
}

bool test_array_creation() {
    Array* array = (Array*) malloc(sizeof(Array));

    array->size = 1;
    array->data = allocate_array(array->size);

    array->data[0] = 0.;

    if (array->data[0] != 0.) {
        return false;
    }

    return true;
}

bool test_matrix_creation() {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));

    matrix->size_x = 1;
    matrix->size_y = 1;

    matrix->data = allocate_matrix(matrix->size_x, matrix->size_y);

    matrix->data[0][0] = 0.;

    if (matrix->data[0][0] != 0.) {
        return false;
    }

    return true;
}

bool test_free_array() {
    Array* array = (Array*) malloc(sizeof(Array));

    array->size = 1;
    array->data = allocate_array(array->size);

    array->data[0] = 0.;

    free_array(&array);

    if (array != NULL) {
        return false;
    }

    return true;
}

bool test_free_matrix() {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));

    matrix->size_x = 1;
    matrix->size_y = 1;

    matrix->data = allocate_matrix(matrix->size_x, matrix->size_y);

    matrix->data[0][0] = 0.;

    free_matrix(&matrix);

    if (matrix != NULL) {
        return false;
    }

    return true;
}

int main() {
    if (test_matrix_equal()) {
        printf("test_matrix_equal() passed\n");
    } else {
        printf("test_matrix_equal() failed\n");
        return 1;
    }
    
    if (test_to_array()) {
        printf("test_to_array() passed\n");
    } else {
        printf("test_to_array() failed\n");
        return 1;
    }

    if (test_array_creation()) {
        printf("test_array_creation() passed\n");
    } else {
        printf("test_array_creation() failed\n");
        return 1;
    }

    if (test_matrix_creation()) {
        printf("test_matrix_creation() passed\n");
    } else {
        printf("test_matrix_creation() failed\n");
        return 1;
    }

    if (test_free_array()) {
        printf("test_free_array() passed\n");
    } else {
        printf("test_free_array() failed\n");
        return 1;
    }

    if (test_free_matrix()) {
        printf("test_free_matrix() passed\n");
    } else {
        printf("test_free_matrix() failed\n");
        return 1;
    }

    return 0;
}