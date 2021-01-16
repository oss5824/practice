#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 1e9
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int V, E, start;
	cin >> V >> E >> start;
	vector<pair<int, int>>* v = new vector<pair<int, int>>[V + 1];
	int* distance = new int[V + 1];
	fill(distance, distance + V + 1, INF);
	for (int i = 0; i < E; i++)
	{
		int a, b, value;
		cin >> a >> b >> value;
		v[a].push_back(make_pair(b, value));
	}
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0, start));
	distance[start] = 0;
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
			if (distance[next] > cur_distance + next_distance)
			{
				distance[next] = cur_distance + next_distance;
				pq.push(make_pair(-distance[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == INF)printf("INF\n");
		else printf("%d\n", distance[i]);
	}
	return 0;
}