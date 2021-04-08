#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n = 0, count = 0;
	cin >> n;
	for (unsigned int i = 666; i < 1000000000; i++)
	{
		unsigned int len = 0, val = i;
		while (val > 0)
		{
			len++;
			val = val / 10;
		}
		short* arr = new short[len];
		unsigned int q = 0, r = i;
		for (int j = 0; j < len - 1; j++)
		{
			int ten = (int)pow(10, len - j - 1);
			arr[len - j - 1] = r / ten;
			r = r % ten;
		}
		arr[0] = r;
		for (int j = 0; j < len - 2; j++)
		{
			if ((arr[j] == arr[j + 1]) && (arr[j + 1] == arr[j + 2])
				&& (arr[j] == arr[j + 2]) && arr[j] == 6)
			{
				count++;
				break;
			}
		}
		if (count == n)
		{
			printf("%d", i);
			break;
		}
	}
}
