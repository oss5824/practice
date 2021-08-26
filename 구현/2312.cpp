#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int T, N, val, num, cnt, i, j;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		val = N;
		for (i = 2; i <= N; i++) {
			if (val % i != 0)continue;
			num = i, cnt = 0;
			while (val % i == 0)val /= i, cnt++;
			printf("%d %d\n", i, cnt); if (val == 1)break;
		}
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
