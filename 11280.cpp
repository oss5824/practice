#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int>v[20002]; vector<int>rv[20002];
bool visit[20002]; int scc[20002];
stack<int>s;
void dfs(int c) { visit[c] = true; for (int n : v[c])if (!visit[n])dfs(n); s.push(c); }
void r_dfs(int c, int r) { visit[c] = true; scc[c] = r; for (int n : rv[c])if (!visit[n])r_dfs(n, r); }
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, cnt = 0; cin >> n >> m; memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b; 
		a = a > 0 ? a : 10000 - a; b = b > 0 ? b : 10000 - b;
		a = a > 10000 ? a - 10000 : a + 10000; 
		v[a].push_back(b); rv[b].push_back(a);
		a = a > 10000 ? a - 10000 : a + 10000; b = b > 10000 ? b - 10000 : b + 10000;
		v[b].push_back(a); rv[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)if (!visit[i])dfs(i); 
	for (int i = 10001; i <= 10000 + n; i++)if (!visit[i])dfs(i);
	memset(visit, false, sizeof(visit));
	while (!s.empty())
	{
		int cur = s.top(); s.pop();
		if (visit[cur])continue;
		r_dfs(cur, cnt); cnt++;
	}
	bool check = false;
	for (int i = 1; i <= n; i++)if (scc[i] == scc[10000 + i]) { check = true; break; }
	if (check)cout << "0"; else cout << "1";
	return 0;
}