#include<iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector<int>depth(100001, 0);
vector<int>v[100001];
int par[21][100001];
void bfs()
{
	queue<int>q; depth[1] = 1; q.push(1);
	while (!q.empty())
	{
		int cur = q.front(), len = v[cur].size(); q.pop();
		for (int i = 0; i < len; i++)
		{
			int next = v[cur][i];
			if (depth[next] == 0) { depth[next] = depth[cur] + 1; par[0][next] = cur; q.push(next); }
		}
	}
}
int get_parent(int a, int b)
{
	while (depth[a] != depth[b] && depth[a] != 0) { int rem = (int)log2(depth[a] - depth[b]); a = par[rem][a]; }
	if (a == b)return a;
	for (int i = 20; i >= 0; i--)if (par[i][a] != par[i][b]) { a = par[i][a]; b = par[i][b]; }
	return par[0][a];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n;
	for (int i = 0; i < n - 1; i++) { cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	bfs();
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 100000; j++)if (par[i - 1][j] != 0)par[i][j] = par[i - 1][par[i - 1][j]];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b; 
		if (depth[a] < depth[b]) { int tmp = b; b = a; a = tmp; }
		cout << get_parent(a, b) << "\n";
	}
	return 0;
}