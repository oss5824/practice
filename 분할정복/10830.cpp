#include <iostream>
using namespace std;
int n;
long long base[6][6];
long long res[6][6];
void multi(long long A[6][6], long long B[6][6])
{
	int result[6][6];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < n; k++)result[i][j] += A[i][k] * B[k][j];
			result[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)res[i][j] = result[i][j];
}

void recursive(unsigned long long square)
{
	if (square == 1)
	{
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)res[i][j] = base[i][j] % 1000;
	}
	else if (square == 0) {}
	else
	{
		if (square % 2 == 0)
		{
			recursive(square / 2);
			multi(res, res);
		}
		else
		{
			recursive((square - 1) / 2);
			multi(res, res);
			multi(res, base);
		}
	}
}

int main()
{
	unsigned long long B;
	cin >> n >> B;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> base[i][j];
	recursive(B);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)printf("%d ", res[i][j] % 1000);
		printf("\n");
	}
	return 0;
}