#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../shared/array/array.hpp"
#include "../shared/matrix/matrix.hpp"


void print_array(Array<double>* arr);
void insert_array(Array<double>* arr);

void print_matrix(Matrix<double>* matrix);
void insert_matrix(Matrix<double>* arr);

Matrix<double>* _c(Matrix<double>* a, Matrix<double>* b);
Matrix<double>* identity(Matrix<double>* arr);
Matrix<double>* transpose(Matrix<double>* arr);
Matrix<double>* mult(Matrix<double>* a, Matrix<double>* b);
Matrix<double>* inverse(Matrix<double>* matrix);
Array<double>* gauss(Matrix<double>* matrix);
Array<double>* cholesky(Matrix<double>* A, Matrix<double>* b);
Array<double>* decomposition(Matrix<double>* U, Matrix<double>* b);