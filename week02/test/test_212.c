#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculateLinear(int size)
{
	int N;
	float *A;

	A = (float*)malloc(sizeof(float) * (size));

	A[1] = 1;

	for (N = 2; N < size; N++) {
		A[N] = 2.0*A[N-1] + 1;
		printf("A[%d] = %f\n", N, A[N]);
	}

	free(A);
}

void calculateConstant(int size)
{
	int N;

	for (N = 2; N < size; N++) {
		printf("A[%d] = %f\n", N, pow(2.0, N) - 1);
	}
}

int main()
{
	calculateLinear(16);
	calculateConstant(16);
}
