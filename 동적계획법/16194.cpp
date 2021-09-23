#pragma warning(disable:4996)
#define MIN(a,b) (a>b)?(b):(a)
#include<stdio.h>
int N, arr[1001], dist[1001];
int main()
{
	scanf("%d", &N); for (int i = 1; i <= N; i++)scanf("%d", arr + i), dist[i] = arr[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++) {
			dist[i] = MIN(dist[i], dist[i - j] + arr[j]);
		}
	printf("%d", dist[N]);
}