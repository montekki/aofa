#include <stdio.h>
#include <stdlib.h>

void calculateRecc(int size)
{
	int n;
	float *a;

	a = (float*)malloc(sizeof(float) * (size));

	a[0] = 1;

	for (n = 1; n < size; n++) {
		a[n] = ((float)n/((float)n + 1.0)) * a[n-1] + 1.0;

		printf("a[%d] = %f\n", n, a[n]);
	}
	free(a);
}

void calculateSol(int size)
{
	int n;

	for (n = 2; n < size; n++) {
		printf("a[%d] = %f\n", n, (n + 2)/2.0);
	}
}

int main()
{
	calculateRecc(16);
	calculateSol(16);

	return 0;
}
