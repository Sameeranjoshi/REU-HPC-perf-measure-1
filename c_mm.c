#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to multiply two matrices
void matrixMultiplication(double **A, double **B, double **C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
   int size = 1000;
    
    // Allocate memory for matrices
    double **A = (double **)malloc(size * sizeof(double *));
    double **B = (double **)malloc(size * sizeof(double *));
    double **C = (double **)malloc(size * sizeof(double *));
    
    for (int i = 0; i < size; i++) {
        A[i] = (double *)malloc(size * sizeof(double));
        B[i] = (double *)malloc(size * sizeof(double));
        C[i] = (double *)malloc(size * sizeof(double));
    }
    
    // Initialize matrices with random values
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
            B[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Start the timer
    clock_t start_time = clock();

    // Perform matrix multiplication
    matrixMultiplication(A, B, C, size);

    // Calculate the elapsed time
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}

