#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "../../modules/integral/integral.h"


double f(double x) {
    return x;
}

bool test_simple_simpson() {
    double result = simpson_simple(f, -1, 1, 10000000);

    if (fabs(result - 0) < 0.000001) {
        return true;
    }

    return false;
}

bool test_simple_riemman() {
    double result = simpson_simple(f, -1, 1, 10000000);

    if (fabs(result - 0) < 0.000001) {
        return true;
    }

    return false;
}

int main() {
    if (test_simple_simpson()) {
        printf("test_simple_simpson() passed\n");
    } else {
        printf("test_simple_simpson() failed\n");
    }

    if (test_simple_riemman()) {
        printf("test_simple_riemman() passed\n");
    } else {
        printf("test_simple_riemman() failed\n");
    }
}