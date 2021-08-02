#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, M, n, ans, res = 11;
bool visit[10];
int val[10];
void solve(int num, int sum)
{
	if (sum == ans) { int cnt = 0; for (int i = 0; i < M; i++)if (visit[i])cnt++; if (res > cnt)res = cnt; }
	if (num == M)return;
	for (int i = num; i < M; i++) {
		if (!visit[i]) {
			visit[i] = true; 
			solve(i + 1, sum | val[i]);
			visit[i] = false; 
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M); for (int i = 0; i < N; i++) ans = ans | (1 << i);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		for (int j = 0, a; j < n; j++) {
			scanf("%d", &a); int v = 1 << (a - 1); val[i] = val[i] | v;
		}
	}
	solve(0,0);
	if (res == 11)res = -1;
	printf("%d", res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);