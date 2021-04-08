#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M, ret = INF;
bool visit[13];
pair<int, int>chicken[13];
pair<int,int>house[100];

int chicken_count, house_count;
int minDistance()
{
	int sum = 0;
	for (int i = 0; i < house_count; i++)
	{
		int min_dist = INF;
		for (int j = 0; j < chicken_count; j++)
		{
			if (visit[j])
			{
				int x = abs(chicken[j].first - house[i].first);
				int y = abs(chicken[j].second - house[i].second);
				min_dist = min(min_dist, x + y);
			}
		}
		sum += min_dist;
	}
	return sum;
}
void solve()
{
	ret = min(minDistance(), ret);
}
void dfs(int num, int cnt)
{
	if (cnt == M) { solve();  return; }
	for (int i = num; i < chicken_count; i++)
		if (!visit[i]) { visit[i] = true; dfs(i, cnt + 1); visit[i] = false; }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int a; cin >>a;
			if (a == 2)chicken[chicken_count++] = { j,i };
			else if (a == 1)house[house_count++] = { j,i };
		}
	dfs(0, 0);cout << ret;
	return 0;
}
