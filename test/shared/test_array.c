#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../modules/shared/array.h"


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

int main() {
    if (test_array_creation()) {
        printf("test_array_creation() passed\n");
    } else {
        printf("test_array_creation() failed\n");
    }

    if (test_matrix_creation()) {
        printf("test_matrix_creation() passed\n");
    } else {
        printf("test_matrix_creation() failed\n");
    }
}