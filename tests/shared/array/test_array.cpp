#include <iostream>
#include <stdexcept>
#include <stdio.h>

#include "../../src/shared/array/array.hpp"


bool test_create_array() {
    auto a = new Array<double>();
    if (a->getSize() != 0) {
        return false;
    }
    
    try {
        a->at(0);
        return false;
    } catch (std::out_of_range) { /* Passed */ }

    delete a;

    auto b = new Array<double>(2, new double[2]{1., 2.});
    if (b->getSize() != 2) {
        return false;
    }
    if (b->at(0) != 1. || b->at(1) != 2.) {
        return false;
    }
    delete b;

    return true;
}


bool test_create_array_of_zeros() {
    auto a = Array<double>::ofZeros(2);
    if (a->getSize() != 2) {
        return false;
    }
    if (a->at(0) != 0 || a->at(1) != 0) {
        return false;
    }
    delete a;

    return true;
}


bool test_create_array_of_ones() {
    auto a = Array<double>::ofOnes(2);
    if (a->getSize() != 2) {
        return false;
    }
    if (a->at(0) != 1 || a->at(1) != 1) {
        return false;
    }
    delete a;

    return true;
}


bool test_push_back() {
    auto a = new Array<double>();
    a->push_back(1.);
    a->push_back(2.);
    if (a->getSize() != 2) {
        return false;
    }
    if (a->at(0) != 1. || a->at(1) != 2.) {
        return false;
    }
    delete a;

    return true;
}


bool test_equal() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = new Array<double>(2, new double[2]{1., 2.});
    if (!a->equal(b)) {
        return false;
    }
    delete a;
    delete b;

    auto c = new Array<double>(2, new double[2]{1., 2.});
    auto d = new Array<double>(2, new double[2]{1., 3.});
    if (c->equal(d)) {
        return false;
    }
    delete c;
    delete d;

    return true;
}


bool test_copy() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = a->copy();
    if (!a->equal(b)) {
        return false;
    }
    delete a;
    delete b;

    return true;
}


bool test_add_by_scalar() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = a->addByScalar(1.);
    if (b->at(0) != 2. || b->at(1) != 3.) {
        return false;
    }
    delete a;
    delete b;

    return true;
}

bool test_sub_by_scalar() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = a->subByScalar(1.);
    if (b->at(0) != 0. || b->at(1) != 1.) {
        return false;
    }
    delete a;
    delete b;

    return true;
}


bool test_mul_by_scalar() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = a->mulByScalar(2.);
    if (b->at(0) != 2. || b->at(1) != 4.) {
        return false;
    }
    delete a;
    delete b;

    return true;
}


bool test_div_by_scalar() {
    auto a = new Array<double>(2, new double[2]{2., 4.});
    auto b = a->divByScalar(2.);
    if (b->at(0) != 1. || b->at(1) != 2.) {
        return false;
    }
    delete a;
    delete b;

    return true;
}


bool test_add_by_array() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = new Array<double>(2, new double[2]{3., 4.});
    auto c = a->addByArray(b);
    if (c->at(0) != 4. || c->at(1) != 6.) {
        return false;
    }
    delete a;
    delete b;
    delete c;

    return true;
}


bool test_sub_by_array() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = new Array<double>(2, new double[2]{3., 4.});
    auto c = a->subByArray(b);
    if (c->at(0) != -2. || c->at(1) != -2.) {
        return false;
    }
    delete a;
    delete b;
    delete c;

    return true;
}


bool test_mul_by_array() {
    auto a = new Array<double>(2, new double[2]{1., 2.});
    auto b = new Array<double>(2, new double[2]{3., 4.});
    auto c = a->mulByArray(b);
    if (c->at(0) != 3. || c->at(1) != 8.) {
        return false;
    }
    delete a;
    delete b;
    delete c;

    return true;
}


bool test_div_by_array() {
    auto a = new Array<double>(2, new double[2]{2., 4.});
    auto b = new Array<double>(2, new double[2]{2., 2.});
    auto c = a->divByArray(b);
    if (c->at(0) != 1. || c->at(1) != 2.) {
        return false;
    }
    delete a;
    delete b;
    delete c;

    return true;
}


int main() {
    if (test_create_array()) {
        printf("test_create_array() passed\n");
    } else {
        printf("test_create_array() failed\n");
        return 1;
    }

    if (test_create_array_of_zeros()) {
        printf("test_create_array_of_zeros() passed\n");
    } else {
        printf("test_create_array_of_zeros() failed\n");
        return 1;
    }

    if (test_create_array_of_ones()) {
        printf("test_create_array_of_ones() passed\n");
    } else {
        printf("test_create_array_of_ones() failed\n");
        return 1;
    }

    if (test_push_back()) {
        printf("test_push_back() passed\n");
    } else {
        printf("test_push_back() failed\n");
        return 1;
    }

    if (test_equal()) {
        printf("test_equal() passed\n");
    } else {
        printf("test_equal() failed\n");
        return 1;
    }

    if (test_copy()) {
        printf("test_copy() passed\n");
    } else {
        printf("test_copy() failed\n");
        return 1;
    }

    if (test_add_by_scalar()) {
        printf("test_add_by_scalar() passed\n");
    } else {
        printf("test_add_by_scalar() failed\n");
        return 1;
    }

    if (test_sub_by_scalar()) {
        printf("test_sub_by_scalar() passed\n");
    } else {
        printf("test_sub_by_scalar() failed\n");
        return 1;
    }

    if (test_mul_by_scalar()) {
        printf("test_mul_by_scalar() passed\n");
    } else {
        printf("test_mul_by_scalar() failed\n");
        return 1;
    }

    if (test_div_by_scalar()) {
        printf("test_div_by_scalar() passed\n");
    } else {
        printf("test_div_by_scalar() failed\n");
        return 1;
    }

    if (test_add_by_array()) {
        printf("test_add_by_array() passed\n");
    } else {
        printf("test_add_by_array() failed\n");
        return 1;
    }

    if (test_sub_by_array()) {
        printf("test_sub_by_array() passed\n");
    } else {
        printf("test_sub_by_array() failed\n");
        return 1;
    }   

    if (test_mul_by_array()) {
        printf("test_mul_by_array() passed\n");
    } else {
        printf("test_mul_by_array() failed\n");
        return 1;
    }

    if (test_div_by_array()) {
        printf("test_div_by_array() passed\n");
    } else {
        printf("test_div_by_array() failed\n");
        return 1;
    }
}