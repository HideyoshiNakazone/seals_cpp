#include <iostream>
#include <memory>

#include "../../modules/shared/array.h"


bool test_array_creation() {
    auto* array = new Array<int>(1);

    array->data[0] = 0.;

    if (array->data[0] != 0.) {
        return false;
    }

    return true;
}

bool test_array_equal() {
    auto* a = new Array<int>(1);
    a->data[0] = 0.;

    auto* b = new Array<int>(1);
    b->data[0] = 0.;

    return a->equal(b);
}

bool test_free_array() {
    std::unique_ptr<Array<int>> array = 
        std::make_unique<Array<int>>(1);

    array.reset();

    if (array != nullptr) {
        return false;
    }

    return true;
}

bool test_matrix_creation() {
    auto* matrix = new Matrix<int>(1, 1);

    matrix->data[0][0] = 0.;

    if (matrix->data[0][0] != 0.) {
        return false;
    }

    return true;
}

bool test_matrix_equal() {
    auto* a = new Matrix<int>(2, 2);

    a->data[0][0] = 1.;
    a->data[0][1] = 1.;
    a->data[1][0] = 1.;
    a->data[1][1] = 1.;

    auto* b = new Matrix<int>(2, 2);
    
    b->data[0][0] = 1.;
    b->data[0][1] = 1.;
    b->data[1][0] = 1.;
    b->data[1][1] = 1.;

    return a->equal(b);
}

bool test_to_array() {
    auto* matrix = new Matrix<int>(1, 1);

    matrix->data[0][0] = 0.;

    Array<int>* array = matrix->to_array();

    if (array->data[0] != 0.) {
        return false;
    }

    return true;
}

bool test_free_matrix() {
    std::unique_ptr<Matrix<int>> matrix = 
        std::make_unique<Matrix<int>>(1, 1);

    matrix->data[0][0] = 0.;

    matrix.reset();

    if (matrix != NULL) {
        return false;
    }

    return true;
}

int main() {
    if (test_array_creation()) {
        std::cout << "test_array_creation() passed\n";
    } else {
        std::cout << "test_array_creation() failed\n";
        return 1;
    }

    if (test_array_equal()) {
        std::cout << "test_array_equal() passed\n";
    } else {
        std::cout << "test_array_equal() failed\n";
        return 1;
    }

    if (test_free_array()) {
        std::cout << "test_free_array() passed\n";
    } else {
        std::cout << "test_free_array() failed\n";
        return 1;
    }

    if (test_matrix_creation()) {
        printf("test_matrix_creation() passed\n");
    } else {
        printf("test_matrix_creation() failed\n");
        return 1;
    }

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

    if (test_free_matrix()) {
        printf("test_free_matrix() passed\n");
    } else {
        printf("test_free_matrix() failed\n");
        return 1;
    }

    return 0;
}