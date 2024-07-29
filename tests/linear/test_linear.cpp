#include "../../src/linear/linear.hpp"


bool test_concatenate_matrix() {
    auto a = std::make_shared<Matrix<double>>();
    a->push_back(Array<double>({1.}));
    a->push_back(Array<double>({1.}));

    auto b = std::make_shared<Matrix<double>>();
    b->push_back(Array<double>({1.}));
    b->push_back(Array<double>({1.}));

    auto c = _c(a, b);

    // for (int i = 0; i < c->size(); i++) {
    //     for (int j = 0; j < c->at(0).size(); j++) {
    //         if (c->at(i).at(j) != 1.) {
    //             return false;
    //         }
    //     }
    // }

    return true;
}

// bool test_identity_matrix_creation() {

//     auto* a = new Matrix<double>(2, 2);

//     identity(a);

//     for (int i = 0; i < a->size_x; i++) {
//         for (int j = 0; j < a->size_y; j++) {
//             if (i == j) {
//                 if (a->data[i][j] != 1.) {
//                     return false;
//                 }
//             } else {
//                 if (a->data[i][j] != 0.) {
//                     return false;
//                 }
//             }
//         }
//     }

//     delete a;

//     return true;
// }

// bool test_transpose_matrix() {
//     auto* a = new Matrix<double>(2, 2);

//     a->data[0][0] = 1.;
//     a->data[0][1] = 2.;
//     a->data[1][0] = 3.;
//     a->data[1][1] = 4.;

//     auto* b = transpose(a);

//     if (b->data[0][0] != 1.) {
//         return false;
//     }

//     if (b->data[0][1] != 3.) {
//         return false;
//     }

//     if (b->data[1][0] != 2.) {
//         return false;
//     }

//     if (b->data[1][1] != 4.) {
//         return false;
//     }

//     delete a;
//     delete b;

//     return true;
// }

// bool test_mult_matrix() {
//     auto* a = new Matrix<double>(2, 2);

//     a->data[0][0] = 1.;
//     a->data[0][1] = 1.;
//     a->data[1][0] = 1.;
//     a->data[1][1] = 1.;

//     auto* b = new Matrix<double>(2, 1);

//     b->data[0][0] = 2.;
//     b->data[1][0] = 2.;

//     auto* c = mult(a, b);

//     if (c->data[0][0] != 4.) {
//         return false;
//     }

//     if (c->data[1][0] != 4.) {
//         return false;
//     }

//     delete a;
//     delete b;
//     delete c;

//     return true;
// }

// bool test_inverse_matrix() {

//     auto* a = new Matrix<double>(3, 3);

//     a->data[0][0] = +01.;
//     a->data[0][1] = +00.;
//     a->data[0][2] = +04.;

//     a->data[1][0] = +01.;
//     a->data[1][1] = +01.;
//     a->data[1][2] = +06.;

//     a->data[2][0] = -03.;
//     a->data[2][1] = +00.;
//     a->data[2][2] = -10.;

//     auto* expected_inverse =  new Matrix<double>(3, 3);
    
//     expected_inverse->data[0][0] = -5.;
//     expected_inverse->data[0][1] = +0.;
//     expected_inverse->data[0][2] = -2.;

//     expected_inverse->data[1][0] = -4.;
//     expected_inverse->data[1][1] = +1.;
//     expected_inverse->data[1][2] = -1.;

//     expected_inverse->data[2][0] = +1.5;
//     expected_inverse->data[2][1] = +0.;
//     expected_inverse->data[2][2] = +0.5;

//     auto* b = inverse(a);

//     return b->equal(expected_inverse);
// }

// bool test_gauss_method() {
//     auto* a = new Matrix<double>(3, 3);

//     a->data[0][0] = 0.;
//     a->data[0][1] = 1.;
//     a->data[0][2] = 2.;

//     a->data[1][0] = 1.;
//     a->data[1][1] = 1.;
//     a->data[1][2] = 3.;

//     a->data[2][0] = 0.;
//     a->data[2][1] = 1.;
//     a->data[2][2] = 2.;

//     auto* expected_array = new Array<double>(2);
    
//     expected_array->data[0] = 1.;
//     expected_array->data[1] = 2.;

//     auto* b = gauss(a);

//     return b->equal(expected_array);
// }

// bool test_cholesky_method() {
//     auto* a = new Matrix<double>(3, 3);

//     a->data[0][0] = 4.;
//     a->data[0][1] = 12.;
//     a->data[0][2] = -16.;

//     a->data[1][0] = 12.;
//     a->data[1][1] = 37.;
//     a->data[1][2] = -43.;

//     a->data[2][0] = -16.;
//     a->data[2][1] = -43.;
//     a->data[2][2] = 98.;

//     auto* b = new Matrix<double>(3, 1);

//     b->data[0][0] = 1.;
//     b->data[1][0] = 2.;
//     b->data[2][0] = 3.;

//     Array<double>* result = cholesky(a, b);

//     Array<double>* expected_array = new Array<double>(3);
    
//     expected_array->data[0] = 28.583333;
//     expected_array->data[1] = -7.666667;
//     expected_array->data[2] = 1.333333;

//     return result->equal(expected_array);
// }

// bool test_decomposition_method() {
//     auto* U = new Matrix<double>(3, 3);

//     U->data[0][0] = +3.;
//     U->data[0][1] = -6.;
//     U->data[0][2] = -3.;

//     U->data[1][0] = +2.;
//     U->data[1][1] = +0.;
//     U->data[1][2] = +6.;

//     U->data[2][0] = -4.;
//     U->data[2][1] = +7.;
//     U->data[2][2] = +4.;

//     auto* b = new Matrix<double>(3, 1);

//     b->data[0][0] = -03.;
//     b->data[1][0] = -22.;
//     b->data[2][0] = +03.;

//     Array<double>* result = decomposition(U, b);

//     Array<double>* expected_array = new Array<double>(3);

//     expected_array->data[0] = -2.;
//     expected_array->data[1] = +1.;
//     expected_array->data[2] = -3.;

//     return result->equal(expected_array);
// }

int main() {
    if (test_concatenate_matrix()) {
        printf("test_concatenate_matrix() passed\n");
    } else {
        printf("test_concatenate_matrix() failed\n");
        return 1;
    }

    // if (test_identity_matrix_creation()) {
    //     printf("test_identity_matrix_creation() passed\n");
    // } else {
    //     printf("test_identity_matrix_creation() failed\n");
    //     return 1;
    // }

    // if (test_transpose_matrix()) {
    //     printf("test_transpose_matrix() passed\n");
    // } else {
    //     printf("test_transpose_matrix() failed\n");
    //     return 1;
    // }

    // if (test_mult_matrix()) {
    //     printf("test_mult_matrix() passed\n");
    // } else {
    //     printf("test_mult_matrix() failed\n");
    //     return 1;
    // }

    // if (test_inverse_matrix()) {
    //     printf("test_inverse_matrix() passed\n");
    // } else {
    //     printf("test_inverse_matrix() failed\n");
    //     return 1;
    // }

    // if (test_gauss_method()) {
    //     printf("test_gauss_method() passed\n");
    // } else {
    //     printf("test_gauss_method() failed\n");
    //     return 1;
    // }

    // if (test_cholesky_method()) {
    //     printf("test_cholesky_method() passed\n");
    // } else {
    //     printf("test_cholesky_method() failed\n");
    //     return 1;
    // }

    // if (test_decomposition_method()) {
    //     printf("test_decomposition_method() passed\n");
    // } else {
    //     printf("test_decomposition_method() failed\n");
    //     return 1;
    // }

    return 0;
}