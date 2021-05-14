#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int T, N;
int par[3001];
bool visit[3001];
pair<pair<int, int>, int>v[3001];
int Find(int x) { if (par[x] == x)return x; else return par[x] = Find(par[x]); }
void Merge(int x, int y)
{
	x = Find(x); y = Find(y); if (x == y)return;
	if (x < y)par[x] = y;
	else if (x > y)par[y] = x;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++) { cin >> v[i].first.first >> v[i].first.second >> v[i].second; par[i] = i; }
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
			{
				double dist = pow(v[i].first.first - v[j].first.first, 2) +
					pow(v[i].first.second - v[j].first.second, 2);
				double distance = pow(v[i].second + v[j].second, 2);
				if (dist <= distance)Merge(i, j);
			}
		for (int i = 0; i < N; i++)visit[Find(par[i])] = true;
		int cnt = 0; for (int i = 0; i < N; i++)if (visit[i])cnt++;
		cout << cnt << "\n";
	}

	return 0;
}