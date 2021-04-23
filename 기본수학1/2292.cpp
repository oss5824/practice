#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int num = 0;
	int lower = 0, upper = 0;
	int result = 1;
	cin >> num;
	if (num == 1)
	{
		printf("1");
		return 0;
	}
	for (int add_l = 0,add_u = 1;; add_l++, add_u++)
	{
		lower += add_l;
		upper += add_u;
		result++;
		if (1 + 6 * lower < num && num <= 1 + 6 * upper)break;
	}
	printf("%d", result);
	return 0;
}

