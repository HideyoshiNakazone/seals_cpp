#include "linear.h"


void print_matrix(Matrix *a) {
    if (a == NULL) {
        printf("NULL Matrix\n");
        return;
    }

    for (int i=0; i<a->size_x; i++) {
        for (int j=0; j<a->size_y; j++) {
            printf("%lf ", a->data[i][j]);
        }
        printf("\n");
    }
}

void insert_matrix(Matrix *matrix) {
    double temp;

    for (int i=0; i < matrix->size_x; i++) {
        for (int j=0; j < matrix->size_y; j++) {
            printf("Insira o valor do elemento %dx%d: ", i+1, j+1);
            scanf("%lf",&temp);
            matrix->data[i][j] = temp;
        }
        printf("\n");
    }
}

void print_array(Array *a) {

    for (int i=0; i<a->size; i++) {
        printf("%lf ", a->data[i]);
    }
    printf("\n");
}

void insert_array(Array *array) {
    double temp;

    for (int i=0; i < array->size; i++) {
        printf("Insira o valor do elemento %d: ", i+1);
        scanf("%lf",&temp);
        array->data[i] = temp;
    }
}

Matrix* _c(Matrix* a, Matrix* b) {   
    if (a->size_y != b->size_y) {
        printf("Matrizes incompativeis para concatenacao\n");
        return NULL;
    }

    Matrix* c = (Matrix*)malloc(sizeof(Matrix));

    c->size_x = a->size_x + b->size_x;
    c->size_y = a->size_y;

    c->data = allocate_matrix(c->size_x, c->size_y);

    for (int i = 0; i < c->size_x; i++) {
        for (int j = 0; j < c->size_y; j++) {
            if (i < a->size_x) {
                c->data[i][j] = a->data[i][j];
            } else {
                c->data[i][j] = b->data[i-a->size_x][j];
            }
        }
    }

    return c;
}

Matrix* identity(Matrix* I) {

    for (int i = 0; i < I->size_x; i++) {
        for (int j = 0; j < I->size_y; j++) {
            if (i == j) {
                I->data[i][j] = 1;
            } else {
                I->data[i][j] = 0;
            }
        }
    }

    return I;
}

Matrix* transpose(Matrix* input) {
    Matrix* transposed = (Matrix*)malloc(sizeof(Matrix));
    transposed->size_x = input->size_y;
    transposed->size_y = input->size_x;

    transposed->data = allocate_matrix(transposed->size_x, transposed->size_y);

    for (int i = 0; i < transposed->size_x; i++) {
        for (int j = 0; j < transposed->size_y; j++) {
            double temp = input->data[i][j];
            transposed->data[i][j] = input->data[j][i];
            transposed->data[j][i] = temp;
        }
    }

    return transposed;
}

Matrix* mult(Matrix* a, Matrix* b) {   
    if (a->size_y != b->size_x) {
        printf("Matrizes incompativeis para multiplicacao\n");
        return NULL;
    }

    Matrix* c = (Matrix*)malloc(sizeof(Matrix));
    c->size_x = a->size_x;
    c->size_y = b->size_y;

    c->data = allocate_matrix(c->size_x, c->size_y);

    for (int i = 0; i < c->size_x; i++) {
        for (int j = 0; j < c->size_y; j++) {
            for (int k = 0; k < c->size_x; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    
    return c;
}

Matrix* inverse(Matrix* matrix) {
    if (matrix->size_x != matrix->size_y) {
        printf("Invalid matrix. The matrix must be quadratic for the calculation of an inverse.\n");
        return NULL;
    }

    Matrix* extended = (Matrix*)malloc(sizeof(Matrix));

    extended->size_x = matrix->size_x;
    extended->size_y = matrix->size_y*2;

    extended->data = allocate_matrix(extended->size_x, extended->size_y);

    for (int i = 0; i < extended->size_x; i++) {
        for (int j = 0; j < extended->size_y; j++) {
            if (j < matrix->size_x) {
                extended->data[i][j] = matrix->data[i][j];
            } else {
                if (i == (j - matrix->size_y)) {
                    extended->data[i][j] = 1;
                } else {
                    extended->data[i][j] = 0;
                }
            }
        }
    }

    int i = 0;
    while (i < extended->size_x) {
        if (extended->data[i][i] == 0) {
            int n = i+1;
            while (n < extended->size_x && extended->data[n][i] == 0) {
                n++;
            }
            if (n == extended->size_x) {
                printf("Invalid matrix. The matrix must be invertible.\n");
                return NULL;
            }

            for (int j = 0; j < extended->size_y; j++) {
                double temp = extended->data[i][j];
                extended->data[i][j] = extended->data[n][j];
                extended->data[n][j] = temp;
            }
        }

        for (int j = 0; j < extended->size_x; j++) {
            if (extended->data[i][i] == 0 || i == j) {
                continue;
            }
            double m = extended->data[j][i] / extended->data[i][i];
            for (int k = 0; k < extended->size_y; k++) {
                extended->data[j][k] -= m * extended->data[i][k];
            }
        }

        if (extended->data[i][i] != 0) {
            double div = extended->data[i][i];
            for (int j = 0; j < extended->size_y; j++) {
                extended->data[i][j] /= div;
            }
        }

        i += 1;
    }

    Matrix* inverse = (Matrix*)malloc(sizeof(Matrix));
    inverse->size_x = matrix->size_x;
    inverse->size_y = matrix->size_y;

    inverse->data = allocate_matrix(inverse->size_x, inverse->size_y);

    for (int i = 0; i < inverse->size_x; i++) {
        for (int j = 0; j < inverse->size_y; j++) {
            inverse->data[i][j] = extended->data[i][j+inverse->size_y];
        }
    }

    free_matrix(&extended);
    
    return inverse;
}

Array* gauss(Matrix* matrix) {
    if ((matrix->size_x + 1) < matrix->size_y) {
        printf("Invalid matrix. The matrix must have more rows than columns for the calculation of a solution.\n");
        return NULL;
    }

    int i = 0;
    int valid_solutions_count = 0;
    while (i < matrix->size_x) {
        if (matrix->data[i][i] == 0) {
            int n = i+1;
            while (n < matrix->size_x && matrix->data[n][i] == 0) {
                n++;
            }
            if (n == matrix->size_x) {
                break;
            }

            for (int j = 0; j < matrix->size_y; j++) {
                double temp = matrix->data[i][j];
                matrix->data[i][j] = matrix->data[n][j];
                matrix->data[n][j] = temp;
            }
        }
        valid_solutions_count += 1;
        for (int j = 0; j < matrix->size_x; j++) {
            if (matrix->data[i][i] == 0 || i == j) {
                continue;
            }
            double m = matrix->data[j][i] / matrix->data[i][i];
            for (int k = 0; k < matrix->size_y; k++) {
                matrix->data[j][k] -= m * matrix->data[i][k];
            }
        }

        i += 1;
    }

    Array* solution = (Array*)malloc(sizeof(Array));
    solution->size = valid_solutions_count;

    solution->data = allocate_array(solution->size);

    for (int i = 0; i < solution->size; i++) {
        solution->data[i] = matrix->data[i][matrix->size_y-1] / matrix->data[i][i];
    }

    return solution;
}

Array* cholesky(Matrix* A, Matrix* b) {
    if (A->size_x != b->size_x && b->size_y != 1) {
        printf("Invalid matrix. The matrix must have the same number of rows as the array for the calculation of a solution.\n");
        return NULL;
    }

    Matrix* g = (Matrix*)malloc(sizeof(Matrix));
    g->size_y = A->size_y;
    g->size_x = A->size_x;

    g->data = allocate_matrix(g->size_x, g->size_y);

    for ( int i=0; i < g->size_x; i++ )
    {
        for ( int j = 0; j < g->size_y; j++)
        {
           g->data[i][j] = 0;
        }
    }

    for (int i = 0; i < g->size_y; i++) {
        for (int j = 0; j <= i; j++) {

            double sum = 0;
            if (i == j) {
                for (int k = 0; k < j; k++) {
                    sum += pow(g->data[j][k], 2);
                }
                g->data[i][j] = sqrt(A->data[i][j] - sum);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += g->data[i][k]*g->data[j][k];
                }
                g->data[i][j] = (A->data[i][j] - sum)/(g->data[j][j]);
            }
        }
    }

    Matrix* gt = transpose(g);

    Matrix* y = mult(inverse(g),b);

    return to_array(mult(inverse(gt),y));
}

Array* decomposition(Matrix* U, Matrix* b) {
    if (U->size_x != b->size_x && b->size_y != 1) {
        printf("Invalid matrix. The matrix must have the same number of rows as the array for the calculation of a solution.\n");
        return NULL;
    }
    Matrix* L = (Matrix*)malloc(sizeof(Matrix));
    L->size_y = U->size_y;
    L->size_x = U->size_x;

    L->data = allocate_matrix(L->size_x, L->size_y);

    identity(L);

    for (int i = 0; i < U->size_x; i++) {

        if ( U->data[i][i] == 0 )
        {                
            int n = i;
            while (U->data[i][i] == 0 && n < U->size_x) {
                for (int m = 0; m < U->size_x; m++) {
                    double swap = U->data[i][m];
                    U->data[i][m] = U->data[n][m];
                    U->data[n][m] = swap;
                }
                
                n += 1;
            }
        }

        for (int k = 0; k < U->size_x; k++) {    
            if ((k > i) && U->data[i][i] != 0) {
                L->data[k][i] = U->data[k][i]/U->data[i][i];

                for ( int m = 0; m < U->size_x; m++ ) {
                    U->data[k][m] = U->data[k][m] - L->data[k][i]*U->data[i][m];
                }
            }
        }
    }

    double *y = mult(inverse(L),b);

    return to_array(mult(inverse(U),y));
}
