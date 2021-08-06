#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, arr[1000], dp[1000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", arr + i); dp[i] = 1e9; }
	dp[0] = 0;
	for (int i = 0; i < N; i++){
		for (int j = i; j < N && j <= i + arr[i]; j++)if (dp[j] > dp[i] + 1)dp[j] = dp[i] + 1;
	}
	if (dp[N - 1] == 1e9)dp[N - 1] = -1;
	printf("%d", dp[N - 1]);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);