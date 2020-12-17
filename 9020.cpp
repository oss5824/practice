#pragma warning(disable:4996)
#include <iostream>
#include <math.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int count = 0;
	cin >> count;
	int* num = new int[count];
	for (int i = 0; i < count; i++)cin >> num[i];
	for (int k = 0; k < count; k++)
	{
		int* store = new int[num[k]];
		int number = 0, result = -1, min = 0, max = 0;
		memset(store, 0, sizeof(int) * num[k]);
		for (int i = 2; i <= num[k]; i++)
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
			if (flag == 1)
			{
				store[number] = i;
				number++;
			}
		}
		for (int i = 0; i < number; i++)
		{
			for (int j = i; j < number; j++)
			{
				int val = store[j];
				int value = num[k] - store[i];
				if (val == value)
				{
					if (store[j] - store[i] < result || result == -1)
					{
						min = store[i];
						max = store[j];
						result = max - min;
					}
				}
			}
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}


