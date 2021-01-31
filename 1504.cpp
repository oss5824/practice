#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 1e9
using namespace std;
vector<pair<int, int>>* v;
int* dist;
int V, E;
int shortest(int b, int e)
{
	fill(dist, dist + V + 1, INF);
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0, b));
	dist[b] = 0;
	while (!(pq.empty()))
	{
		int cur_distance = -pq.top().first;
		int cur = pq.top().second;
		int len = v[cur].size();
		pq.pop();
		for (int i = 0; i < len; i++)
		{
			int next = v[cur][i].first;
			int next_distance = v[cur][i].second;
			if (dist[next] > cur_distance + next_distance)
			{
				dist[next] = cur_distance + next_distance;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	return dist[e];
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int v1, v2;
	cin >> V >> E;
	v = new vector<pair<int, int>>[V + 1];
	dist = new int[V + 1];
	for (int i = 0; i < E; i++)
	{
		int a, b, value;
		cin >> a >> b >> value;
		v[a].push_back(make_pair(b, value));
		v[b].push_back(make_pair(a, value));
	}
	cin >> v1 >> v2;
	int startToV1 = shortest(1, v1), V1ToV2 = shortest(v1, v2), V2ToEnd = shortest(v2, V);
	bool INF1 = (startToV1 == INF || V1ToV2 == INF || V2ToEnd == INF) ? true : false;
	int startToV2 = shortest(1, v2), V2ToV1 = V1ToV2, V1ToEnd = shortest(v1, V);
	bool INF2 = (startToV2 == INF || V2ToV1 == INF || V1ToEnd == INF)? true : false;
	if (INF1 && INF2)printf("-1");
	else printf("%d", min(startToV2 + V2ToV1 + V1ToEnd,
		startToV1 + V1ToV2 + V2ToEnd));
	return 0;
}
