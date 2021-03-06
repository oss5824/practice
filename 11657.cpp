#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 10e9
typedef long long ll;
vector<pair<int, ll>>v[501];
ll dist[501];
int cnt[501];
bool visit[501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, c; cin >> n >> m; fill(dist, dist + 501, INF);
	while (m--) { cin >> a >> b >> c; v[a].push_back({ b,c }); }
	queue<int>q; q.push(1); dist[1] = 0; visit[1] = true; cnt[1]++;
	while (!q.empty())
	{
		int cur = q.front(); q.pop(); visit[cur] = false;
		for (pair<int, ll> next : v[cur])
			if (dist[next.first] > dist[cur] + next.second)
			{
				dist[next.first] = dist[cur] + next.second;
				if (!visit[next.first])
				{
					cnt[next.first]++; if (cnt[next.first] >= n) { cout << "-1"; return 0; }
					q.push(next.first); visit[next.first] = true;
				}
			}
	}
	for (int i = 2; i <= n; i++)(dist[i] != INF) ? cout << dist[i] << "\n" : cout << "-1\n";
	return 0;
}