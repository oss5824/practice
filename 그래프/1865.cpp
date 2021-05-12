#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int T, N, M, W;
int Map[501][501];
int dist[501];
vector<int>v[501];
bool inQ[501];
int cycle[501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> N >> M >> W;
		memset(inQ, false, sizeof(inQ));
		for (int i = 1; i <= 500; i++) { for (int j = 1; j <= 500; j++)Map[i][j] = INF; v[i].clear(); }
		for (int i = 0; i < M; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			if (Map[a][b] == INF)v[a].push_back(b);
			if (Map[b][a] == INF)v[b].push_back(a);
			Map[a][b] = min(c, Map[a][b]); Map[b][a] = min(c, Map[b][a]);
		}
		for (int i = 0; i < W; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			if (Map[a][b] == INF)v[a].push_back(b);
			Map[a][b] = min(-c, Map[a][b]);
		}
		bool check = false;
		for (int i = 1; i <= N; i++)
		{
			queue<int>q; q.push(i); fill(dist, dist + N + 1, INF);
			bool check2 = false;
			dist[i] = 0; memset(inQ, false, sizeof(inQ)); memset(cycle, 0, sizeof(cycle));
			inQ[i] = true; cycle[i]++;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				inQ[cur] = false;
				if (dist[i] < 0) { check = true; break; }
				for (int next : v[cur]) {
					if (!inQ[next])
					{
						if (dist[next] > dist[cur] + Map[cur][next])
						{
							dist[next] = dist[cur] + Map[cur][next];
							cycle[next]++;
							if (cycle[next] >= N)
							{
								check2 = true;
								break;
							}
							q.push(next);
							inQ[next] = true;
						}
					}
				}
				if (check2)break;
			}
			if (check)break;
		}
		if (check)cout << "YES\n"; else cout << "NO\n";
	}
	return 0;
}