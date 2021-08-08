#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
int N, M, a, d[2][41];
bool v[41];
int s(int n, int c)
{
	if (n == N + 1)return 1;
	if (d[c][n] != -1)return d[c][n];
	if (v[n])return d[c][n] = s(n + 1, 1);
	if (c)d[c][n] = s(n + 1, 0);
	else {
		d[c][n] = s(n + 1, 0);
		d[c][n] += s(n + 1, 1);
	}
	return d[c][n];
}
int main()
{
	scanf("%d %d", &N, &M); while (M--) { scanf("%d", &a); v[a] = 1; }
	memset(d, -1, sizeof(d));
	printf("%d", s(1, 1));
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);