#include <stdio.h>

// Function to multiply two matrices and count operations
void multiplyMatrices(int n, int A[][n], int B[][n], int C[][n], long long *operation_count)
{
    *operation_count = 0; // Initialize operation count

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j]; // Multiplication + Addition
                *operation_count += 2;        // Counting one multiplication and one addition
            }
        }
    }
}

// Function to print a matrix (for debugging, optional)
void printMatrix(int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function to run experiments
int main()
{
    int n_values[] = {10, 20, 50, 100, 200}; // Matrix sizes for experiments
    int num_tests = sizeof(n_values) / sizeof(n_values[0]);

    for (int t = 0; t < num_tests; t++)
    {
        int n = n_values[t];

        // Declare matrices
        int A[n][n], B[n][n], C[n][n];

        // Initialize matrices with dummy values (not required for operation count)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = 1;
                B[i][j] = 1;
            }
        }

        long long operation_count = 0;

        // Perform matrix multiplication and count operations
        multiplyMatrices(n, A, B, C, &operation_count);

        // Print results
        printf("Matrix size: %d x %d, Operation count: %lld\n", n, n, operation_count);
    }

    return 0;
}
