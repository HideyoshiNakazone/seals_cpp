#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../modules/shared/array.h"
#include "../modules/linear/linear.h"


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

bool test_inverse_matrix() {

    Matrix* a = (Matrix*) malloc(sizeof(Matrix));
    a->size_x = 3;
    a->size_y = 3;

    a->data = allocate_matrix(a->size_x, a->size_y);
    a->data[0][0] = +01.;
    a->data[0][1] = +00.;
    a->data[0][2] = +04.;

    a->data[1][0] = +01.;
    a->data[1][1] = +01.;
    a->data[1][2] = +06.;

    a->data[2][0] = -03.;
    a->data[2][1] = +00.;
    a->data[2][2] = -10.;

    Matrix* expected_inverse = (Matrix*) malloc(sizeof(Matrix));
    expected_inverse->size_x = 3;
    expected_inverse->size_y = 3;

    expected_inverse->data = allocate_matrix(expected_inverse->size_x, expected_inverse->size_y);
    
    expected_inverse->data[0][0] = -5.;
    expected_inverse->data[0][1] = +0.;
    expected_inverse->data[0][2] = -2.;

    expected_inverse->data[1][0] = -4.;
    expected_inverse->data[1][1] = +1.;
    expected_inverse->data[1][2] = -1.;

    expected_inverse->data[2][0] = +1.5;
    expected_inverse->data[2][1] = +0.;
    expected_inverse->data[2][2] = +0.5;

    Matrix* b = inverse(a);

    return equal_matrix(b, expected_inverse);
}

bool test_gauss_method() {
    Matrix* a = (Matrix*) malloc(sizeof(Matrix));
    a->size_x = 3;
    a->size_y = 3;

    a->data = allocate_matrix(a->size_x, a->size_y);

    a->data[0][0] = 0.;
    a->data[0][1] = 1.;
    a->data[0][2] = 2.;

    a->data[1][0] = 1.;
    a->data[1][1] = 1.;
    a->data[1][2] = 3.;

    a->data[2][0] = 0.;
    a->data[2][1] = 1.;
    a->data[2][2] = 2.;

    Array* expected_array = (Array*) malloc(sizeof(Array));
    expected_array->size = 2;

    expected_array->data = allocate_array(expected_array->size);
    expected_array->data[0] = 1.;
    expected_array->data[1] = 2.;

    Array* b = gauss(a);

    return equal_array(b, expected_array);
}

bool test_cholesky_method() {
    Matrix* a = (Matrix*) malloc(sizeof(Matrix));
    a->size_x = 3;
    a->size_y = 3;

    a->data = allocate_matrix(a->size_x, a->size_y);

    a->data[0][0] = 4.;
    a->data[0][1] = 12.;
    a->data[0][2] = -16.;

    a->data[1][0] = 12.;
    a->data[1][1] = 37.;
    a->data[1][2] = -43.;

    a->data[2][0] = -16.;
    a->data[2][1] = -43.;
    a->data[2][2] = 98.;

    Matrix* b = (Matrix*) malloc(sizeof(Matrix));
    b->size_x = 1;
    b->size_y = 3;

    b->data = allocate_matrix(b->size_x, b->size_y);
    b->data[0][0] = 1.;
    b->data[0][1] = 2.;
    b->data[0][2] = 3.;

    Array* result = cholesky(a, b);

    Array* expected_array = (Array*) malloc(sizeof(Array));
    expected_array->size = 3;

    expected_array->data = allocate_array(expected_array->size);
    
    expected_array->data[0] = 28.583333;
    expected_array->data[1] = -7.666667;
    expected_array->data[2] = 1.333333;

    // print_array(result);

    return equal_array(result, expected_array);
}

int main() {
    if (test_matrix_equal()) {
        printf("test_matrix_equal() passed\n");
    } else {
        printf("test_matrix_equal() failed\n");
        return 1;
    }

    if (test_concatenate_matrix()) {
        printf("test_concatenate_matrix() passed\n");
    } else {
        printf("test_concatenate_matrix() failed\n");
        return 1;
    }

    if (test_identity_matrix_creation()) {
        printf("test_identity_matrix_creation() passed\n");
    } else {
        printf("test_identity_matrix_creation() failed\n");
        return 1;
    }

    if (test_transpose_matrix()) {
        printf("test_transpose_matrix() passed\n");
    } else {
        printf("test_transpose_matrix() failed\n");
        return 1;
    }

    if (test_mult_matrix()) {
        printf("test_mult_matrix() passed\n");
    } else {
        printf("test_mult_matrix() failed\n");
        return 1;
    }

    if (test_inverse_matrix()) {
        printf("test_inverse_matrix() passed\n");
    } else {
        printf("test_inverse_matrix() failed\n");
        return 1;
    }

    if (test_gauss_method()) {
        printf("test_gauss_method() passed\n");
    } else {
        printf("test_gauss_method() failed\n");
        return 1;
    }

    if (test_cholesky_method()) {
        printf("test_cholesky_method() passed\n");
    } else {
        printf("test_cholesky_method() failed\n");
        return 1;
    }

    return 0;
}