#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	unsigned long long n;
	int count = 0;
	int arr[10] = { 0, };
	cin >> n;
	unsigned long long n2 = n;
	while (n2 > 0)
	{
		count++;
		n2 = n2 / 10;
	}
	for (int i = 0; i < count; i++)
	{
		long long val = n / pow(10, count - i - 1);
		arr[val]++;
		n = n % (int)pow(10, count - i - 1);
	}
	for (int i = 9; i >= 0; i--)
	{
		long long len = arr[i];
		for (int j = 0; j < len; j++)printf("%d", i);
	}
	return 0;
}
