
#include <stdio.h>
#include <stdlib.h>

/*
constructs an m x n 2d array implemented as an array of
pointers to arrays.The array of pointers of type float *
as well as the sub-arrays of floats of type float should
be dynamically allocated using malloc.
*/
void matrixArrayOfArrays(int m, int n)
{
    // Allocate memory for the array of pointers
    float **matrix = (float **)malloc(m * sizeof(float *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (float *)malloc(n * sizeof(float));
    }
    // Fill the array with values
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = i * n + j + 1;
        }
    }
    // print row by row
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f\t ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // print column by column
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%f\t ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

/*
constructs an m x n 2d array implemented as an array of pointers, and one large
contiguous block of memory. The array of pointers of type float * as well as the
large array of type  float should be dynamically allocated using malloc.
*/
void matrixOneBigArray(int m, int n)
{
    // Allocate memory for the array of pointers
    float **matrix = (float **)malloc(m * sizeof(float *));
    float *bigArray = (float *)malloc(m * n * sizeof(float));
    // Set the pointers to the start of each row
    for (int i = 0; i < m; i++)
    {
        matrix[i] = bigArray + i * n;
    }
    for (int i = 0; i < m * n; i++)
    {
        bigArray[i] = i + 1;
    }
    // print row by row
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f\t ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // print column by column
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%f\t ", matrix[i][j]);
        }
        printf("\n");
    }
    free(bigArray);
    free(matrix);
}

#define M 5
#define N 6

int main(int argc, char **argv)
{
    matrixArrayOfArrays(M, N);
    printf("\n");
    matrixOneBigArray(M, N);
    return 0;
}