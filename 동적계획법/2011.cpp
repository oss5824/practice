#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstring>
#define INF 1000000
char str[5001];
int len,dp[5000];
int solve(int pos)
{
	if (str[pos] == '0')return 0;
	if (len <= pos)return 1;
	if (dp[pos] != -1)return dp[pos];
	if (pos != len - 1) {
		if (str[pos] == '1' || (str[pos] == '2' && str[pos + 1] <= '6'))
			dp[pos] = (solve(pos + 1) + solve(pos + 2));
		else dp[pos] = solve(pos + 1);
	}
	else dp[pos] = solve(pos + 1);
	return dp[pos] % INF;
}
int main()
{
	scanf("%s", str); len = strlen(str); memset(dp, -1, sizeof(dp));
	printf("%d",solve(0));
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);