#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
typedef long long ll;
int N;
ll d[31][31];
ll s(int a, int b)
{
	if (a + b == 0)return 1;
	if (d[a][b] != -1)return d[a][b];
	ll c = 0;
	if (a != 0)c += s(a - 1, b);
	if (b != 0)c += s(a + 1, b - 1);
	return d[a][b] = c;
}
int main()
{
	while (1) {
		scanf("%d", &N); if (N == 0)break;
		memset(d, -1, sizeof(d)); printf("%lld\n", s(0, N));
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);