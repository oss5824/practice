#include <iostream>
using namespace std;
int main()
{
	int n;
	unsigned long long result = 0;
	cin >> n;
	unsigned long long** store = new unsigned long long* [n + 1];
	for (int i = 1; i <= n; i++)store[i] = new unsigned long long[11];
	for (int i = 1; i < 10; i++)store[1][i] = 1;
	store[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)store[i][0] = store[i - 1][1] % 1000000000;
			else if (j == 9)store[i][9] = store[i - 1][8] % 1000000000;
			else store[i][j] = (store[i - 1][j - 1] + store[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 0; i <= 9; i++)result += store[n][i];
	printf("%llu", result % 1000000000);
	return 0;
}
