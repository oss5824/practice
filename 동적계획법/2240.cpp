#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
#define max(a,b) (a)>(b)?(a):(b)
int N, M, v[1000], dp[2][31][1000];
int solve(int n, int m, int x)
{
	if (n == N)return 0;
	int& r = dp[x - 1][m][n];
	if (r != -1)return r;
	int mx = 3 - x;
	if (m == 0)r = solve(n + 1, m, x) + (v[n] == x);
	else if (v[n] == x) r = max(solve(n + 1, m, x) + 1, solve(n + 1, m - 1, mx));
	else r = max(solve(n + 1, m, x), solve(n + 1, m - 1, mx) + 1);
	return r;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", v + i);
	memset(dp, -1, sizeof(dp));
	printf("%d", solve(0, M, 1));
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);