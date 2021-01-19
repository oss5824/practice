#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 1e9
using namespace std;
vector<pair<int, long long>>* v;
long long** dist;
int V, E;
bool bellman(int start)
{
	dist[start][start] = 0;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (dist[start][j] == INF)continue;
			int len = v[j].size();
			long long cur_distance = dist[start][j];
			for (int k = 0; k < len; k++)
			{
				int next = v[j][k].first;
				long long next_distance = v[j][k].second;
				if (dist[start][next] > cur_distance + next_distance)
					dist[start][next] = cur_distance + next_distance;
			}
		}
	}
	return true;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> V >> E;
	v = new vector<pair<int, long long>>[V + 1];
	dist = new long long*[V + 1];
	for (int i = 0; i <= V; i++)dist[i] = new long long[V + 1];
	for (int i = 0; i <= V; i++)for (int j = 0; j <= V; j++)dist[i][j] = INF;
	for (int i = 0; i < E; i++)
	{
		int a, b, value;
		cin >> a >> b >> value;
		v[a].push_back(make_pair(b, value));
	}
	for (int i = 1; i <= V; i++) bellman(i);
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (dist[i][j] == INF)printf("0 ");
			else printf("%lld ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
