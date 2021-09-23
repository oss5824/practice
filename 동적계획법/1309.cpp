#pragma warning(disable:4996)
#include<stdio.h>
int dp[100000][3], N;
int rec(int n, int k)
{
	if (n == N - 1)return 1;
	int& ret = dp[n][k];
	if (ret != -1)return ret % 9901;
	if (k == 0)ret = rec(n + 1, 1) % 9901;
	else if (k == 1)ret = rec(n + 1, 0) % 9901;
	else ret = rec(n + 1, 0) % 9901 + rec(n + 1, 1);
	ret += rec(n + 1, 2) % 9901;
	return ret % 9901;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)dp[i][0] = -1, dp[i][1] = -1, dp[i][2] = -1;
	printf("%d", (rec(0, 0) + rec(0, 1) + rec(0, 2)) % 9901);
}