#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, v[1001], s, m, e = 1000, val, sum;
int main()
{
	scanf("%d", &N);
	for (int i = 0, a, b; i < N; i++) {
		scanf("%d %d", &a, &b); v[a] = b;if (val < b) { val = b; m = a; }
	}while (!v[s])s++; while (!v[e])e--;
	for (int i = s; i <= m; i++){if (v[s] < v[i]) { s = i; }sum += v[s];}
	for (int i = e; i > m; i--) {if (v[e] < v[i]) { e = i; }sum += v[e];}
	printf("%d", sum);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


