#include <iostream>
#include <memory>

#include "../../../src/shared/array/array.hpp"


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

    return 0;
}