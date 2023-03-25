#ifndef array_h
#define array_h

// Type definitions
typedef struct _Array {
    double* data;
    int size;
} Array;

typedef struct _Matrix{
    double** data;

    int size_x;
    int size_y;
} Matrix;

#endif

// Auxiliary Functions

Array* to_array(Matrix* matrix);

// Define Data Allocation Functions

double* allocate_array(int size);

double** allocate_matrix(int size_x, int size_y);

// Define Data Free Functions

void free_array(Array** array);

void free_matrix(Matrix** matrix);