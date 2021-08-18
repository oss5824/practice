#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	long long N, V, M, n = 1, s = 1, v, r, nc = 0;
	scanf("%lld %lld", &N, &M); V = M;
	while (1) {
		if (N > 9 * n)nc += 9 * n * s;
		else { nc += N * s; break; }
		N -= 9 * n; n *= 10; s++;
	}
	if (nc < M) { printf("-1"); return 0; }
	s = 1; n = 1;
	while (M - 9 * n * s > 0) { M -= 9 * n * s; n *= 10; s++; }
	v = n + (M - 1) / s;  r = (M) % s; n = 1; for (int i = 0; i < s - r; i++)n *= 10;
	if (r == 0)printf("%lld", v % 10);
	else printf("%lld", (v / n) % 10);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);