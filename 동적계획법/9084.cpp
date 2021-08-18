#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int T; scanf("%d", &T);
	while (T--) {
		int N, v[20], M, dp[10001] = {}; scanf("%d", &N);
		for (int i = 0; i < N; i++)scanf("%d", v + i);
		scanf("%d", &M);
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = v[i]; j <= M; j++) {
				dp[j] += dp[j - v[i]];
			}
		}
		printf("%d\n", dp[M]);
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);