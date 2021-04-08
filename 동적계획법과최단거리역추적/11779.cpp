#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#define INF 1e9
using namespace std;
pair<pair<int, string>, int>M[1001];
int n, m;
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<pair<int, int>>* v = new vector<pair<int, int>>[n + 1];
	for (int i = 0; i < m; i++)
	{
		int s, e, value;
		cin >> s >> e >> value;
		v[s].push_back({ e,value });
	}
	int start, end;
	cin >> start >> end;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });
	for (int i = 0; i <= n; i++)M[i] = { { INF,"" },0 };
	M[start] = { { 0,to_string(start) + " " },1 };
	while (!pq.empty())
	{
		int cur_distance = pq.top().first;
		int cur = pq.top().second;
		int len = v[cur].size();
		pq.pop();
		if (cur == end) 
		{ cout << M[cur].first.first << "\n" << M[cur].second << "\n" << M[cur].first.second; break; }
		for (int i = 0; i < len; i++)
		{
			int next_distance = v[cur][i].second;
			int next = v[cur][i].first;
			if ( M[next].first.first > cur_distance + next_distance)
			{
				pq.push({ cur_distance + next_distance,next });
				M[next] = { { (cur_distance + next_distance),M[cur].first.second + to_string(next) + " " }
				,M[cur].second + 1 };
			}
		}
	}
	return 0;
}