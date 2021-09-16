#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int V, E, arr[100001], num;
vector<int>v[100001];
vector<pair<int, int>>res;
int dfs(int n,int b)
{
	arr[n] = ++num;
	int cur = arr[n];
	for (int next : v[n]) {
		if (next == b)continue;
		if (arr[next]) {
			cur = min(cur, arr[next]);
			continue;
		}
		int val = dfs(next, n);
		if (val > arr[n]) { res.push_back({ min(n,next),max(n,next) }); }
		cur = min(cur, val);
	}
	return cur;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> V >> E;
	while (E--) { int a, b; cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	for (int i = 1; i <= V; i++)if (!arr[i])dfs(i, 0);
	int cnt = 0;
	sort(res.begin(), res.end()); res.erase(unique(res.begin(), res.end()), res.end());
	cout << res.size() << "\n";
	for (pair<int, int>p : res)cout << p.first << " " << p.second << "\n";
}