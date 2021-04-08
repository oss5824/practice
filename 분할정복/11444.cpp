#include <iostream>
using namespace std;
unsigned long long  n;
unsigned long long base[2][2];
unsigned long long res[2][2];
void multi(unsigned long long A[2][2], unsigned long long B[2][2])
{
	unsigned long long int result[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 2; k++)result[i][j] += (A[i][k] * B[k][j]) % 1000000007;
			result[i][j] %= 1000000007;
		}
	}
	for (int i = 0; i < 2; i++)for (int j = 0; j < 2; j++)res[i][j] = result[i][j];
}
void recursive(unsigned long long n)
{
	if (n == 1)
	{
		res[0][0] = 1, res[0][1] = 1, res[1][0] = 1, res[1][1] = 0;
	}
	else if (n == 0) {}
	else
	{
		if (n % 2 == 0)
		{
			recursive(n / 2);
			multi(res, res);
		}
		else
		{
			recursive((n - 1) / 2);
			multi(res, res);
			multi(res, base);
		}
	}

}
int main()
{
	cin >> n;
	base[0][0] = 1, base[0][1] = 1, base[1][0] = 1, base[1][1] = 0;
	recursive(n);
	printf("%llu", res[0][1] % 1000000007);
	return 0;
}