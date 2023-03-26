#include "lib2.h"

extern "C" float SinIntegral(float a, float b, float e) 
{
	float result = 0;
	int n = (int) ((b-a) / e);

	for (int i = 1 ; i < n ; ++i) 
	{
		result += std::sin(a + i * e);
  	}

 	result += (std::sin(a) + std::sin(b)) / 2;
  	result *= e; 

  	return result;
}


extern "C" int PrimeCount(int A, int B)
{
	int result = 0;

	const int sz = B;
	int mas[sz + 1] = {0};

	for (int i = 2; i <= sz; i++)
	{
		mas[i] = i;
	}


	for (int i = 2; i <= sz; i++)
	{
		if (mas[i] == 0)
			continue;

		for (int j = i + 1; j <= sz; j++)
		{
			if (mas[j] == 0) 
				continue;
			
			if (mas[j] % mas[i] == 0)
			{
				mas[j] = 0;
			}
		}

		result += 1;
	}


	return result;
}
