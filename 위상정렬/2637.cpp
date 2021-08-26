#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int N, M, a, b, c, lv[101], num[101];
bool r[101];
vector<pair<int, int>>v[101];
int main()
{
	scanf("%d %d", &N, &M); 	
	queue<int>q; q.push(N); num[N] = 1;
	while (M--) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c }); lv[b]++; r[a] = 1;
	}
	while (!q.empty()) {
		a = q.front(); q.pop();
		for (pair<int, int>p : v[a]) {
			num[p.first] += num[a] * p.second;
			if (!(--lv[p.first]))q.push(p.first);
		}
	}
	for (int i = 1; i <= N; i++)if (!r[i] && num[i])printf("%d %d\n", i, num[i]);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
