#pragma warning(disable: 4996)
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
typedef long long ll;
using namespace std;
int T, n, d, c;
int a, b, s;
int dist[10001];
vector<pair<int, int>>v[10001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> d >> c;
		fill(dist, dist + n + 1, INF);
		for (int i = 1; i <= n; i++)v[i].clear();
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		pq.push({ 0,c }); dist[c] = 0;
		while (!pq.empty()) {
			int cur = pq.top().second, curD = pq.top().first; pq.pop();

			if (dist[cur] < curD)continue;

			for (pair<int, int>next : v[cur]) {
				if (next.second + dist[cur] < dist[next.first]) {
					dist[next.first] = next.second + dist[cur];
					pq.push({ dist[next.first],next.first });
				}
			}
		}
		int cnt = 0, result = 0;
		for (int i = 1; i <= n; i++){
			if (dist[i] == INF)continue; cnt++; result = max(result, dist[i]);
		}
		cout << cnt << " " << result << "\n";
	}
	return 0;
}


