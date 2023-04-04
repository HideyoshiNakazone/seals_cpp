#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../modules/root/root.h"


double f(double x) {
    return x;
}

double df(double x) {
    return 1;
}

bool close(double result, double expected, double eps) {
    return fabs(result - expected) < eps;
}

bool test_bissec() {
    double eps = 0.000001;
    double result = bissec(f, -1, 1, eps);

    if (close(result, 0, eps)) {
        return true;
    }

    return false;
}

bool test_newton() {
    double eps = 0.000001;
    double result = newton(f, df, 0.5, eps);

    if (close(result, 0, eps)) {
        return true;
    }

    return false;
}

bool test_mist() {
    double eps = 0.000001;
    double result = mist(f, df, -1, 1, eps);

    if (close(result, 0, eps)) {
        return true;
    }

    return false;
}

int main() {
    if (test_bissec()) {
        printf("Test bissec passed\n");
    } else {
        printf("Test bissec failed\n");
    }

    if (test_newton()) {
        printf("Test newton passed\n");
    } else {
        printf("Test newton failed\n");
    }

    if (test_mist()) {
        printf("Test mist passed\n");
    } else {
        printf("Test mist failed\n");
    }
    
}