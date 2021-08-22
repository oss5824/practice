#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define min(a,b) (a)>(b)?(b):(a)
int N, M, K, i, s, v;
int pos[101], dis[101], p, d;
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i <= K; i++) {
		scanf("%d %d", &pos[i], &dis[i]);
		if (pos[i] == 2)dis[i] = 2 * N + M - dis[i];
		else if (pos[i] == 3)dis[i] = 2 * N + 2 * M - dis[i];
		else if (pos[i] == 4)dis[i] += N;
	}
	p = pos[K], d = dis[K];
	for (i = 0; i < K; i++) s += min(abs(d - dis[i]), 2 * N + 2 * M - abs(d - dis[i]));
	printf("%d", s);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

/*
5 2 10
9 4 8 1 5
->´ä 9
*/