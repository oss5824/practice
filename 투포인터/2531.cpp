#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, d, k, c, cnt, res, v[30000], type[3001];
int main()
{
	scanf("%d %d %d %d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++)scanf("%d", v + i);
	for (int i = 0; i < k; i++) if (type[v[i]]++ == 0) cnt++;
	res = cnt; if (type[c] == 0)res++;
	for (int s = 0, e = k; s < N - 1; s++, e++) {
		if (--type[v[s]] == 0)cnt--;
		if (++type[v[e % N]] == 1)cnt++;
		if (res <= cnt) { res = cnt; if (type[c] == 0)res++; }
	}printf("%d", res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);