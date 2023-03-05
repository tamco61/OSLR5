#include "lib1.h"

// Riemann sum
float SinIntegral(float A, float B, float e)
{
	float result = 0, n = (int) ((B - A) / e);

	for (int i = 0; i < n; i++)
		result += std::sin(A + e / 2 + i * e);

	result *= e;

	return result;
}

// Simple Algo
int PrimeCount(int A, int B)
{

	int result = 0, flag;

	for (int 	i = A; i <= B; i++)
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

		if (flag)
			continue;
		else
			result += 1;
	}


	return result;
}
