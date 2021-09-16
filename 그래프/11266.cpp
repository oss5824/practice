#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int V, E, arr[10001], num;
bool check[10001];
vector<int>v[10001];
int dfs(int n, bool root)
{
	arr[n] = ++num;
	int cur = arr[n], cnt = 0;
	for (int next : v[n]) {
		if (!arr[next]) {
			cnt++;
			int val = dfs(next, false);
			if (!root && val >= arr[n]) check[n] = true;
			cur = min(cur, val);
		}
		else cur = min(cur, arr[next]);
	}
	if (root && cnt >= 2)check[n] = true;
	return cur;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> V >> E;
	while (E--) { int a, b; cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	for (int i = 1; i <= V; i++)if (!arr[i])dfs(i, true);
	int cnt = 0;
	for (int i = 1; i <= V; i++)if (check[i])cnt++; cout << cnt << "\n";
	for (int i = 1; i <= V; i++)if (check[i])cout << i << " ";
}