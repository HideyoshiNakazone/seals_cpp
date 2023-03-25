#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#include "shared/array.h"


void print(Matrix* arr);
void insert(Matrix* arr);

Matrix* _c(Matrix* a, Matrix* b);
Matrix* identity(Matrix* arr);
Matrix* transpose(Matrix* arr);
Matrix* mult(Matrix* a, Matrix* b);
// Matrix* inverse(Matrix* matrix);
// Matrix* gauss(Matrix* matriz);
// Matrix* cholesky(Matrix* A, Matrix* b);
// Matrix* decomposition(Matrix* U, Matrix* b);