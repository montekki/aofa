#include <stdio.h>
#include <stdlib.h>

void calculateRecc(int size)
{
	int n;
	float *a;

	a = (float*)malloc(sizeof(float) * (size));

	a[0] = 0;

	for (n = 1; n < size; n++) {
		a[n] = ((n + 1.0)*a[n-1] + 2.0 * n)/(float)n;

		printf("a[%d] = %f\n", n, a[n]);
	}
}

float harmonic(int N)
{
	if (N == 0.0)
		return 0.0;

	return (1.0/(float)N + harmonic(N - 1));
}

void calculateSol(int size)
{
	int n;

	for (n = 1; n < size; n++) {
		printf("a[%d] = %f\n", n, 2.0 * (harmonic(n+1) - 1.0) * (n + 1.0));
	}
}

int main()
{
	calculateRecc(16);
	calculateSol(16);

	return 0;
}
