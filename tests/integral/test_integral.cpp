#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "../../modules/integral/integral.h"


double f(double x) {
    return x;
}

double g(double x, double y) {
    return x*y;
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

bool test_double_riemman() {
    double result = riemann_double(g, -1, 1, -1, 1, 10000);

    if (fabs(result - 0) < 0.000001) {
        return true;
    }

    return false;
}

bool test_double_simpson() {
    double result = simpson_double(g, -1, 1, -1, 1, 10000);

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

    if (test_double_riemman()) {
        printf("test_double_riemman() passed\n");
    } else {
        printf("test_double_riemman() failed\n");
    }

    if (test_double_simpson()) {
        printf("test_double_simpson() passed\n");
    } else {
        printf("test_double_simpson() failed\n");
    }
}