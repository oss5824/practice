#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int T, N;
bool p[1000001];
int main()
{
	vector<int>v;
	for (int i = 2; i * i <= 1000000; i++) {
		if (p[i])continue;
		for (int j = i + i; j <= 1000000; j += i)p[j] = true;
	}
	vector<int>v;
	for (int i = 2; i <= 1000000; i++)if (!p[i])v.push_back(i);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int s = 0, e = v.size() - 1, cnt = 0;
		while (s <= e) { if (v[s] + v[e] == N)s++, e--, cnt++; else if (v[s] + v[e] > N)e--; else s++; }
		printf("%d\n", cnt);
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
