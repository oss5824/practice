#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
typedef long long ll;
int N, ans, arr[99];
ll dp[99][21];
ll solve(int idx, int sum)
{
	if (idx == 0) return dp[0][sum] = (sum == arr[0]);
	if (dp[idx][sum] != -1)return dp[idx][sum];
	int a = sum + arr[idx], b = sum - arr[idx];
	ll c = 0;
	if (a <= 20)c += solve(idx - 1, a); if (0 <= b)c += solve(idx - 1, b);
	return dp[idx][sum] = c;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)scanf("%d", arr + i);
	scanf("%d", &ans); memset(dp, -1, sizeof(dp));
	printf("%lld", solve(N - 2, ans));
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);