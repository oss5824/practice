#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1;; i++){
		int dp[31];
		for (int j = 1;; j++) {
			int dp[31]; dp[0] = i; dp[1] = j;
			for (int k = 2; k < N; k++) {
				dp[k] = dp[k - 1] + dp[k - 2];
				if (k == N - 1 && dp[k] == M) { printf("%d\n%d", i, j); return 0; }
			}
			if (dp[N - 1] > M)break;
		}
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);