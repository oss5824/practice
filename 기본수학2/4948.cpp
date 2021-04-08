#pragma warning(disable:4996)
#include <iostream>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int count = 0, all[300] = { 0, };
	while (1)
	{
		int num = 0;
		cin >> num;
		if (num == 0)break;
		all[count] = num;
		count++;
	}
	for (int k = 0; k < count; k++)
	{
		int num = all[k], num2 = 2 * all[k], value = 0;
		for (int i = num+1; i <= num2; i++)
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
			if (flag == 1 && i != 1)value++;
		}
		printf("%d\n", value);
	}
	return 0;
}


