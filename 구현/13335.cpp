#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, W, L;
int p[1000], w[1000];
int main()
{
	scanf("%d %d %d", &N, &W, &L);
	for (int i = 0; i < N; i++)scanf("%d", &w[i]);
	int s = 0, cur = 0, res = 0;
	while (1) {
		if (p[N - 1] == W)break;
		int sum = 0;
		for (int i = s; i <= cur; i++) { p[i]++; sum += w[i]; }
		if (cur != N - 1) {
			if (p[s] == W)sum -= w[s++];
			if (sum + w[cur + 1] <= L)cur++;
		}res++;
	}printf("%d", ++res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

/*
5 2 10
9 4 8 1 5
->´ä 9
*/