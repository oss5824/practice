#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>v[32001];
int level[32001];
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n >> m; for (int i = 0; i < m; i++) { cin >> a >> b; level[b]++; v[a].push_back(b); }
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 1; i <= n; i++)if (level[i] == 0)q.push(i);
	while (!q.empty()) {
		int cur = q.top(); q.pop(); 
		cout << cur << " ";
		for (int next : v[cur])if (--level[next] == 0)q.push(next);
	}
	return 0;
}