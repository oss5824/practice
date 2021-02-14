#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
vector<int>* v, * rv;
vector<int>value, rest, scc, result, arr; vector<bool>visit, scc_visit;
stack<int>s;
void dfs(int c) { visit[c] = true; for (int n : v[c])if (!visit[n]) dfs(n); s.push(c); }
void r_dfs(int c, int r)
{
	visit[c] = true; scc[c] = r; result[r] += value[c];for (int n : rv[c])if (!visit[n])r_dfs(n, r);
}
void cal(int start)
{
	visit[start] = true; scc_visit[scc[start]] = true;
	for (int n : v[start])
	{
		if (!visit[n])
		{
			if (!scc_visit[scc[n]]) { arr[scc[n]] = arr[scc[start]] + result[scc[n]]; scc_visit[scc[n]] = true; }
			else if (scc[start] != scc[n])arr[scc[n]] = max(arr[scc[n]], arr[scc[start]] + result[scc[n]]);
			cal(n);
		}
		else if (scc[start] != scc[n])arr[scc[n]] = max(arr[scc[n]], arr[scc[start]] + result[scc[n]]);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, start, number, cnt = 0, max_value = 0; cin >> n >> m;
	v = new vector<int>[n + 1]; rv = new vector<int>[n + 1]; value.assign(n + 1, 0); visit.assign(n + 1, false);
	for (int i = 0; i < m; i++) { cin >> a >> b; v[a].push_back(b); rv[b].push_back(a); }
	for (int i = 1; i <= n; i++)cin >> value[i];cin >> start >> number; rest.assign(number, 0); 
	for (int i = 0; i < number; i++)cin >> rest[i];
	for (int i = 1; i <= n; i++)if (!visit[i])dfs(i); 
	visit.assign(n + 1, false); scc.assign(n + 1, 0); result.assign(n + 1, 0);
	while (!s.empty()) { int cur = s.top(); s.pop(); if (visit[cur])continue; r_dfs(cur, cnt); cnt++; }
	arr.assign(n + 1, 0); visit.assign(n + 1, false); scc_visit.assign(n + 1, false); 
	arr[scc[start]] = result[scc[start]]; cal(start);
	for (int i = 0; i < number; i++)max_value = max(max_value, arr[scc[rest[i]]]);
	if (!scc_visit[scc[start]])max_value += result[scc[start]];
	cout << max_value;
	return 0;
}