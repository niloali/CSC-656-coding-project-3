#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {
   #pragma omp parallel for
   for (int i = 0; i < n; ++i) {
       double sum = 0.0;
       for (int j = 0; j < n; ++j) {
           sum += A[i * n + j] * x[j];
       }
       y[i] += sum;

   
   }

}

