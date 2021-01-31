#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 1e9
using namespace std;
vector<pair<int, long long>>* v;
long long* dist;
int V, E;
bool bellman()
{
	dist[1] = 0;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (dist[j] == INF)continue;
			int len = v[j].size();
			long long cur_distance = dist[j];
			for (int k = 0; k < len; k++)
			{
				int next = v[j][k].first;
				long long next_distance = v[j][k].second;
				if (dist[next] > cur_distance + next_distance)
				{
					dist[next] = cur_distance + next_distance;
					if (i == V)return false;
				}
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
	dist = new long long[V + 1];
	fill(dist, dist + V + 1, INF);
	for (int i = 0; i < E; i++)
	{
		int a, b, value;
		cin >> a >> b >> value;
		v[a].push_back(make_pair(b, value));
	}
	if (!bellman())printf("-1");
	else
	{
		for (int i = 2; i <= V; i++)
		{
			if (dist[i] == INF)printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}
	return 0;
}
