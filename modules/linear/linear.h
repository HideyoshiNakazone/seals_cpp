#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "../shared/array.h"


void print_array(Array* arr);
void insert_array(Array* arr);

void print_matrix(Matrix* matrix);
void insert_matrix(Matrix* arr);

Matrix* _c(Matrix* a, Matrix* b);
Matrix* identity(Matrix* arr);
Matrix* transpose(Matrix* arr);
Matrix* mult(Matrix* a, Matrix* b);
Matrix* inverse(Matrix* matrix);
Array* gauss(Matrix* matriz);
Array* cholesky(Matrix* A, Matrix* b);
Array* decomposition(Matrix* U, Matrix* b);