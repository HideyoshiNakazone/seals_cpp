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

// Define Data Allocation Functions

double* allocate_array(int size);

double** allocate_matrix(int size_x, int size_y);