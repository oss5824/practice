#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
bool* visit;
queue<pair<int, int>>q;
vector<pair<int, int>>* v;
int result = 0, position = 0;
void bfs(int start)
{
	q.push({ start,0 }); visit[start] = true;
	while (!q.empty())
	{
		int cur = q.front().first, cur_dist = q.front().second, len = v[cur].size();
		q.pop();
		for (int i = 0; i < len; i++)
		{
			int child = v[cur][i].first, child_dist = v[cur][i].second, dist = cur_dist + child_dist;
			if (!visit[child])
			{
				q.push({ child,dist }); visit[child] = true;
				position = (dist > result) ? child : position;
				result = max(result, dist);
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, s, e, d;
	cin >> n;
	v = new vector<pair<int, int>>[n + 1]; visit = new bool[n + 1];
	memset(visit, false, sizeof(bool) * (n + 1));
	for (int i = 0; i < n - 1; i++) { cin >> s >> e >> d; v[s].push_back({ e, d }); v[e].push_back({ s, d }); }
	bfs(1);
	memset(visit, false, sizeof(bool) * (n + 1)); result = 0;
	bfs(position);
	cout << result;
	return 0;
}