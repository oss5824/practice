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
int dist[501];
bool inQ[501];
int cycle[501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
		bool check = false;
		memset(inQ, false, sizeof(inQ));
		vector<pair<int, int>>v[501]; fill(dist, dist + N + 1, INF);
		for (int i = 0; i < M; i++){
			int a, b, c; cin >> a >> b >> c;
			v[a].push_back({ b,c }); v[b].push_back({ a,c });
		}
		for (int i = 0; i < W; i++){
			int a, b, c; cin >> a >> b >> c;
			v[a].push_back({ b,-c });
		}
		for (int i = 1; i <= N; i++)
		{
			queue<int>q; q.push(i); memset(cycle, 0, sizeof(cycle));
			dist[i] = 0; inQ[i] = true; cycle[i]++;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				inQ[cur] = false;
				for (pair<int, int> p : v[cur]) {
					int next = p.first, cost = p.second;
					if (dist[next] > dist[cur] + cost){
						dist[next] = dist[cur] + cost;
						if (!inQ[next]){
							cycle[next]++;
							if (cycle[next] >= N){
								check = true;
								break;
							}
							q.push(next);
							inQ[next] = true;
						}
					}
				}
				if (check)break;
			}
			if (check)break;
		}check ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}