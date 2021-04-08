#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	while (1)
	{
		int value[3];
		cin >> value[0] >> value[1] >> value[2];
		if (value[0] == 0 && value[1] == 0 && value[2] == 0)break;
		if (value[0] >= value[1] && value[0] >= value[2])
		{
			int c = (int)pow(value[0], 2);
			int a = (int)pow(value[1], 2);
			int b = (int)pow(value[2], 2);
			if (c == a + b)printf("right\n");
			else printf("wrong\n");
		}
		else if (value[1] >= value[0] && value[1] >= value[2])
		{
			int c = (int)pow(value[1], 2);
			int a = (int)pow(value[0], 2);
			int b = (int)pow(value[2], 2);
			if (c == a + b)printf("right\n");
			else printf("wrong\n");
		}
		else if (value[2] >= value[0] && value[2] >= value[1])
		{
			int c = (int)pow(value[2], 2);
			int a = (int)pow(value[0], 2);
			int b = (int)pow(value[1], 2);
			if (c == a + b)printf("right\n");
			else printf("wrong\n");
		}
	}
	return 0;
}

