#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
int par[21][100001], par_max[21][100001], par_min[21][100001], depth[100001];
int n, m, a, b, c, root;
bool check[100001];
vector<pair<int, int>>v[100001];
void bfs(int val)
{
	queue<int>q; q.push(root); depth[val] = 1; par[0][val] = val;
	par_min[0][val] = 1000001; par_max[0][val] = 0;
	while (!q.empty())
	{
		int cur = q.front(), len = v[cur].size(); q.pop();
		for (int i = 0; i < len; i++)
		{
			int next = v[cur][i].first, next_val = v[cur][i].second;
			if (depth[next] == 0) 
			{
				par[0][next] = cur; q.push(next); par_max[0][next] = next_val; par_min[0][next] = next_val; 
				depth[next] = depth[cur] + 1;
			}
		}
	}
}
void get_par(int a, int b)
{
	int val = 0, max_val = 0, min_val = 1000001;
	while (depth[a] != depth[b])
	{
		val = log2(depth[a] - depth[b]); max_val = max(max_val, par_max[val][a]); min_val = min(min_val, par_min[val][a]);
		a = par[val][a];
	}
	for (int i = 20; i >= 0; i--)
		if (par[i][a] != par[i][b])
		{
			max_val = max(max_val, par_max[i][a]); min_val = min(min_val, par_min[i][a]);
			max_val = max(max_val, par_max[i][b]); min_val = min(min_val, par_min[i][b]);
			a = par[i][a]; b = par[i][b]; 
		}
	max_val = max(max_val, par_max[0][a]); min_val = min(min_val, par_min[0][a]);
	max_val = max(max_val, par_max[0][b]); min_val = min(min_val, par_min[0][b]);
	cout << min_val << " " << max_val << "\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; memset(check, false, sizeof(check)); 
	for (int i = 0; i < n - 1; i++) { cin >> a >> b >> c; check[b] = true; v[a].push_back({ b,c }); v[b].push_back({ a,c }); }
	for (int i = 1; i <= n; i++)if (!check[i]) { root = i; break; }
	if (root == 0)root = 1;
	bfs(root);
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 100000; j++)
			if (par[i - 1][j] != 0)
			{
				par[i][j] = par[i - 1][par[i - 1][j]];
				par_max[i][j] = max(par_max[i - 1][j], par_max[i - 1][par[i - 1][j]]);
				par_min[i][j] = min(par_min[i - 1][j], par_min[i - 1][par[i - 1][j]]);
			}
	cin >> m;
	for (int i = 0; i < m; i++) { cin >> a >> b; if (depth[a] < depth[b]) { int tmp = a; a = b; b = tmp; }get_par(a, b); }
	return 0;
}