#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int, int>>v[1001];
bool visit[1001];
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); memset(visit, false, sizeof(visit));
	int n, m, a, b, c, result = 0; cin >> n >> m;
	for (int i = 0; i < m; i++) { cin >> a >> b >> c; v[a].push_back({ b,c }); v[b].push_back({ a,c }); }
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,1 });
	for (int i = 0; i < n; i++){
		int cur_dist = pq.top().first, cur = pq.top().second; pq.pop();
		if (visit[cur]) { i--; continue; }
		result += cur_dist; visit[cur] = true;
		for (pair<int, int>next : v[cur]) { if (visit[next.first] == false)pq.push({ next.second,next.first }); }
	}
	cout << result;
	return 0;
}