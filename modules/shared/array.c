#include <stdio.h>
#include <stdlib.h>

#include "array.h"


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