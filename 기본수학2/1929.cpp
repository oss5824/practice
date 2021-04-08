#pragma warning(disable:4996)
#include <iostream>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int min = 0, max = 0, count = 0;
	cin >> min >> max;
	for (int i = min; i <= max; i++)
	{
		int flag = 1;
		int length = floor(sqrt(i));
		for (int j = 2; j <= length; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
			if (j == i - 1)flag = 1;
		}
		if (flag == 1 && i != 1)printf("%d\n", i);
	}
}

