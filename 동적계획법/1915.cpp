#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
char Map[1000][1001];
int dp[1000][1000], N, M, res;
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)scanf("%s", Map[i]);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)dp[i][j] = Map[i][j] - '0';
	if (dp[0][0] == 1 || dp[1][0] == 1 || dp[0][1] == 1)res = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++) {
			if (dp[i][j] == 0)continue;
			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			res = max(res, dp[i][j]);
		}
	printf("%d", res * res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);