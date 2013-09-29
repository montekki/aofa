#include <stdio.h>
#include <stdlib.h>

void computeQuad(int size)
{
    float *A = (float*)malloc(sizeof(float) * (size+1));
    float temp;
    int N, j;

    A[0] = 3;
    for (N = 1; N <= size; N++) {
        A[N] = 1;
        temp = 0;

        for (j = 1; j <= N; j++)
            temp += A[j-1];

        temp = (2.0/(float)N) * temp;
        A[N] += temp;

        printf("A[%d] = %f\n", N, A[N]);
    }

    free(A);
}

void computeLinear(int size)
{
    int N;
    float temp;
    float *A = (float*)malloc(sizeof(float) * (size+1));

    A[0] = 3;

    for (N = 1; N <= size; N++) {
        A[N] = (1.0 + ((float)N + 1.0) * A[N-1])/(float)N;

        printf("A[%d] = %f\n", N, A[N]);
    }

    free(A);
}

void computeSimplified(int size)
{
    int N;
    float A0 = 3;
    float AN;

    for (N = 1; N <= size; N++) {
        AN = (float)N*A0 + A0 + (float)N;

        printf("A[%d] = %f\n", N, AN);
    }
}

int main()
{
    printf("Quadratic given formula:\n");
    computeQuad(10);
    printf("\nLinear formula:\n");
    computeLinear(10);
    printf("\nCompute simplified:\n");
    computeSimplified(10);
    return 0;
}
