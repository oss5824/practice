#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n = 0, min = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val = i, qt = 0, rem = i, result = 0, len = 0;
		while (val > 0)
		{
			len++;
			val /= 10;
		}
		for (int j = 0; j < len - 1; j++)
		{
			int ten = (int)pow(10, len - j - 1);
			qt = rem / ten;
			rem = rem % ten;
			result += qt;
		}
		result += rem + i;
		min = ((result < min || min == 0) && result == n) ? i : min;
		if (min < i && min != 0)break;
	}
	printf("%d", min);
	return 0;
}
