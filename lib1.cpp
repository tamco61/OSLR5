#include "lib1.h"
#include "stdio.h"

// Riemann sum
extern "C" float SinIntegral(float A, float B, float e)
{
	float result = 0, n = (int) ((B - A) / e);

	for (int i = 0; i < n; i++)
		result += sin(A + e / 2 + i * e);

	result *= e;

	return result;
}

// Simple Algo
extern "C" int PrimeCount(int A, int B)
{
	int result = 0, flag;

	for (int i = A; i <= B; i++)
	{
		flag = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}

		if (flag || i == 1)
			continue;
		else
			result += 1;
	}


	return result;
}

