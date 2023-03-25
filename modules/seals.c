#include "seals.h"


void print(Matrix *a) {

    for (int i=0; i<a->size_x; i++) {
        for (int j=0; j<a->size_y; j++) {
            printf("%lf ", a->data[i][j]);
        }
        printf("\n");
    }
}

void insert(Matrix *matrix) {
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

bool equal(Matrix* a, Matrix* b) {
    if (a->size_x != b->size_x || a->size_y != b->size_y) {
        return false;
    }

    for (int i = 0; i < a->size_x; i++) {
        for (int j = 0; j < a->size_y; j++) {
            if (a->data[i][j] != b->data[i][j]) {
                return false;
            }
        }
    }

    return true;
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
            while (extended->data[n][i] == 0 && n < extended->size_x) {
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

        if (extended->data[i][i] == -1) {
            for (int j = 0; j < extended->size_y; j++) {
                extended->data[i][j] *= -1;
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
    
    return inverse;
}

// Matrix* gauss(Matrix* input) {
//     int rows = *(input-1);
//     int columns = *(input-2);

//     double *matriz = (double *)malloc(((rows*columns)+2)*sizeof(double));

//     *(matriz) = columns;
//     *(matriz+1) = rows;

//     matriz  = matriz + 2;
    
//     for (int i = 0; i < rows; i++ )
//     {
//         for (int j = 0; j < columns; j++)
//         {
//             *((matriz + i*columns) + j) = *((input + i*columns) + j);
//         }
        
//     }

//     int i=0, j=0, n;

//     while (i < rows)
//     {
//         if ( *((matriz + i*columns) + i ) == 0 )
//         {
//             n = i+1;
//             while (( *((matriz + i*columns) + i) == 0 ) && (n < rows))
//             {
//                 for (int m = 0; m < columns; m++)
//                 {
//                     double swap = *((matriz + i*columns) + m);
//                     *((matriz + i*columns) + m) = *((matriz + n*columns) + m);
//                     *((matriz + n*columns) + m) = swap;
//                 }
//                 n += 1;
//             }
//         }

//         n = 0;

//         while ( n < rows )
//         {

//             if (( n==i ) || (*((matriz + i*columns) + i ) == 0 ))
//             {
//                 n += 1;
//             }
//             else
//             {
//                 double mult = ( *((matriz + n*columns) + i ) )/( *((matriz + i*columns) + i ) );

//                 for ( int m = 0; m < columns; m++ )
//                 {
//                     (*((matriz + n*columns) + m)) = (*((matriz + n*columns) + m)) - mult*( *((matriz + i*columns) + m) );
//                 }

//                 n += 1;
//             }
//         }

//         i += 1;
//         n = 0;
//     }

//     i = 0;

//     while ((i<rows) && (*((matriz + i*columns) + i) != 0))
//     {
//         for ( int m = 0; m < columns; m++)
//         {
//             (*((matriz + i*columns) + m)) = (*((matriz + i*columns) + m))/(*((matriz + i*columns) + i));
//         }

//         i += 1;
//     }

//     return matriz;
// }

// Matrix* cholesky(Matrix* A, Matrix* b) {   
//     int rows = *(A-1);
//     int columns = *(A-2);

//     double *g = (double *)malloc(((rows*columns)+2)*sizeof(double));
    
//     *(g+1) = rows;
//     *g = columns;

//     g = g + 2;

//     for ( int i=0; i < rows; i++ )
//     {
//         for ( int j = 0; j < columns; j++)
//         {
//             *((g + i*columns) + j) = 0;
//         }
//     }

//     int i = 0;
//     int j = 0;
    
//     while (j < rows)
//     {
//         while (i < rows)
//         {
//             if (i == 0 && j == 0)
//             {
//                 *((g + i*columns) + j) = sqrt(*((A + 0*columns) + 0));
//             }
//             else if (j == 0)
//             {
//                 *((g + i*columns) + j) = (*((A + i*columns) + 0))/(*((g + 0*columns) + 0));
//             }
//             else if (i == j)
//             {
//                 int k = 0;
//                 double theta = 0;

//                 while (k < i)
//                 {
//                     theta += pow((*((g + i*columns) + k)),2);
//                     k += 1;
//                 }
//                 *((g + i*columns) + j) = sqrt(*((A + i*columns) + i) - theta);
//             }
//             else
//             {
//                 int k = 0;
//                 float theta = 0;

//                 while (k < j)
//                 {
//                     theta += (*((g + i*columns) + k))*(*((g + j*columns) + k));
//                     k += 1;
//                 }
//                 *((g + i*columns) + j) = (*((A + i*columns) + j) - theta)/(*((g + j*columns) + j));
//             }
//             i += 1;
//         }
//         j += 1;
//         i = j;
//     }

//     double *gt = transpose(g);

//     double *y = mult(inverse(g),b);

//     return mult(inverse(gt),y);
// }

// Matrix* decomposition(Matrix* U, Matrix* b) {
//     int order = *(U-1);
//     double *L = (double *)malloc(((order*order)+2)*sizeof(double));

//     *L = order;
//     *(L+1) = order;

//     L = L + 2; 

//     L = identity(L);

//     int i = 0;
//     int k = 0;
//     int n;

//     while (i < order)
//     {            
//         k = 0;

//         if ( *((U + i*order) + i) == 0 )
//         {                
//             n = i;
            
//             while ((*((U + i*order) + i) == 0) && (n < order))
//             {
//                 for (int m = 0; m < order; m++)
//                 {
//                     double swap = *((U + i*order) + m);
//                     *((U + i*order) + m) = *((U + n*order) + m);
//                     *((U + n*order) + m) = swap;
//                 }
                
//                 n += 1;
//             }
//         }
//         while (k < order)
//         {    
//             if ((k <= i) || (*((U + i*order) + i) == 0))
//             {                    
//                 k += 1;
//             }   
//             else
//             {
//                 *((L + k*order) + i) = (*((U + k*order) + i))/(*((U + i*order) + i));
//                 for ( int m = 0; m < order; m++ )
//                 {
//                     (*((U + k*order) + m)) = (*((U + k*order) + m)) - (*((L + k*order) + i))*(*((U + i*order) + m));
//                 }
//                 k += 1;
//             }
//         }   
//         i += 1;
//     }

//     double *y = mult(inverse(L),b);

//     return mult(inverse(U),y);
// }
