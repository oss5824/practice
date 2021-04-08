#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int min = 0, max = 0, result = 0, value = 0;
	
	cin >> min >> max;

	for (int i = min; i <= max; i++)
	{
		if (i == 1)continue;
		int flag = 1;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
			if (j == i - 1)flag = 1;
		}
		if (flag == 1 && value == 0)value = i;
		if (flag == 1)result += i;
	}
	if (max == 1)printf("-1");
	else if (result != 0)printf("%d\n%d", result, value);
	else printf("-1");
}

