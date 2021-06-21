#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
using namespace std;
vector<int>v[500];
vector<int>rev_v[500];
int arr[500][500], rev_arr[500][500];
int dist[500];
int N, M, S, D;
void GetDistance()
{
	fill(dist, dist + N, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>q;
	q.push({ 0,S }); dist[S] = 0;
	int result = INF;
	while (!q.empty()) {
		int cur = q.top().second, curD = q.top().first; q.pop();
		if (dist[cur] < curD) { continue; }
		for (int next : v[cur]) {
			int nextD = arr[cur][next];
			if (curD + nextD < dist[next]) {
				dist[next] = curD + nextD;
				q.push({ dist[next],next });
			}
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		cin >> S >> D;
		memset(arr, 0, sizeof(arr)); memset(rev_arr, 0, sizeof(rev_arr));
		for (int i = 0; i < N; i++) { v[i].clear(); rev_v[i].clear(); }
		while (M--) {
			int a, b, c; cin >> a >> b >> c; v[a].push_back(b); rev_v[b].push_back(a);
			if (arr[a][b] == 0)arr[a][b] = c; else arr[a][b] = min(arr[a][b], c);
			if (rev_arr[b][a] == 0)rev_arr[b][a] = c; else rev_arr[b][a] = min(rev_arr[b][a], c);
		}		
		GetDistance();

		queue<int>q; q.push(D);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int prev : rev_v[cur]) {
				if (dist[prev] == dist[cur] - rev_arr[cur][prev]) {
					q.push(prev); rev_arr[cur][prev] = INF; arr[prev][cur] = INF;
				}
			}
		}
		GetDistance();
		if (dist[D] != INF)cout << dist[D] << "\n"; else cout << "-1\n";
	}
;	return 0;
}

