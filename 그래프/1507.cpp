#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int v[20][20], N, sum, com;
bool c[20][20];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) { scanf("%d", &v[i][j]); if (i > j)sum += v[i][j]; }
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++) {
				if (k == i || i == j || k == j || c[i][j])continue;
				if (v[i][k] + v[k][j] < v[i][j]) { printf("-1"); return 0; }
				else if (v[i][k] + v[k][j] == v[i][j]) { c[i][j] = true; com += v[i][j]; }
			}
	printf("%d", sum - com);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


