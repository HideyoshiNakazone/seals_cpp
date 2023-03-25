#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../modules/shared/array.h"
#include "../modules/seals.h"


bool test_concatenate_matrix() {

    Matrix* a = (Matrix*) malloc(sizeof(Matrix));

    a->size_x = 2;
    a->size_y = 1;

    a->data = allocate_matrix(a->size_x, a->size_y);
    a->data[0][0] = 1.;
    a->data[1][0] = 1.;

    Matrix* b = (Matrix*) malloc(sizeof(Matrix));
    b->size_x = 2;
    b->size_y = 1;

    b->data = allocate_matrix(b->size_x, b->size_y);
    b->data[0][0] = 1.;
    b->data[1][0] = 1.;

    Matrix* c = _c(a, b);

    for (int i = 0; i < c->size_x; i++) {
        for (int j = 0; j < c->size_y; j++) {
            if (c->data[i][j] != 1.) {
                return false;
            }
        }
    }

    return true;
}

bool test_identity_matrix_creation() {
    Matrix* a = (Matrix*) malloc(sizeof(Matrix));

    a->size_x = 2;
    a->size_y = 2;

    a->data = allocate_matrix(a->size_x, a->size_y);

    identity(a);

    for (int i = 0; i < a->size_x; i++) {
        for (int j = 0; j < a->size_y; j++) {
            if (i == j) {
                if (a->data[i][j] != 1.) {
                    return false;
                }
            } else {
                if (a->data[i][j] != 0.) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool test_transpose_matrix() {
    Matrix* a = (Matrix*) malloc(sizeof(Matrix));

    a->size_x = 2;
    a->size_y = 2;

    a->data = allocate_matrix(a->size_x, a->size_y);

    a->data[0][0] = 1.;
    a->data[0][1] = 2.;
    a->data[1][0] = 3.;
    a->data[1][1] = 4.;

    Matrix* b = transpose(a);

    if (b->data[0][0] != 1.) {
        return false;
    }

    if (b->data[0][1] != 3.) {
        return false;
    }

    if (b->data[1][0] != 2.) {
        return false;
    }

    if (b->data[1][1] != 4.) {
        return false;
    }

    return true;
}

bool test_mult_matrix() {
    Matrix* a = (Matrix*) malloc(sizeof(Matrix));

    a->size_x = 2;
    a->size_y = 2;

    a->data = allocate_matrix(a->size_x, a->size_y);

    a->data[0][0] = 1.;
    a->data[0][1] = 2.;
    a->data[1][0] = 3.;
    a->data[1][1] = 4.;

    Matrix* b = (Matrix*) malloc(sizeof(Matrix));

    b->size_x = 2;
    b->size_y = 2;

    b->data = allocate_matrix(b->size_x, b->size_y);

    b->data[0][0] = 1.;
    b->data[0][1] = 2.;
    b->data[1][0] = 3.;
    b->data[1][1] = 4.;

    Matrix* c = mult(a, b);

    if (c->data[0][0] != 7.) {
        return false;
    }

    if (c->data[0][1] != 10.) {
        return false;
    }

    if (c->data[1][0] != 15.) {
        return false;
    }

    if (c->data[1][1] != 22.) {
        return false;
    }

    return true;
}

int main() {
    if (test_concatenate_matrix()) {
        printf("test_concatenate_matrix() passed\n");
    } else {
        printf("test_concatenate_matrix() failed\n");
    }

    if (test_identity_matrix_creation()) {
        printf("test_identity_matrix_creation() passed\n");
    } else {
        printf("test_identity_matrix_creation() failed\n");
    }

    if (test_transpose_matrix()) {
        printf("test_transpose_matrix() passed\n");
    } else {
        printf("test_transpose_matrix() failed\n");
    }

    if (test_mult_matrix()) {
        printf("test_mult_matrix() passed\n");
    } else {
        printf("test_mult_matrix() failed\n");
    }

    return 0;
}