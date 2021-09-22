#include<stdio.h>
long long dp[201][201], N, K;
int main()
{
	scanf("%d %d", &N, &K); for (int i = 0; i <= N; i++)dp[1][i] = 1;
	for (int i = 2; i <= K; i++)
		for (int j = 0; j <= N; j++) 
			for (int k = 0; k <= j; k++)dp[i][j] += dp[i - 1][k], dp[i][j] %= (int)1e9;		
	printf("%d", dp[K][N]);
}