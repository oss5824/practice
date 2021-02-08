
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int>* v;
bool* visit, * check;
int* depth, * parent;
void bfs(int root)
{
	queue<int>q; visit[root] = true; depth[root] = 1; q.push(root);
	while (!q.empty())
	{
		int cur = q.front(), len = v[cur].size(); q.pop();
		for (int i = 0; i < len; i++)
		{
			int n = v[cur][i];
			if (!visit[n]) { visit[n] = true; depth[n] = depth[cur] + 1; q.push(n); parent[n] = cur; }
		}
	}
}
int find_parent(int a, int b)
{
	if (depth[a] != depth[b])while (depth[a] != depth[b])a = parent[a];
	while (a != b) { a = parent[a]; b = parent[b]; }
	return a;
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int T, n, a, b, c, d, root = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n; v = new vector<int>[n + 1]; visit = new bool[n + 1]; parent = new int[n + 1];
		depth = new int[n + 1]; check = new bool[n + 1];
		memset(depth, 0, sizeof(int) * (n + 1)); memset(parent, 0, sizeof(int) * (n + 1));
		memset(visit, false, sizeof(bool) * (n + 1)); memset(check, false, sizeof(bool) * (n + 1));
		for (int i = 0; i < n - 1; i++) { cin >> a >> b; v[a].push_back(b); check[b] = true; }
		for (int i = 1; i <= n; i++)if (!check[i]) { root = i; break; }
		bfs(root); cin >> c >> d;
		if (c == d) { cout << c << "\n"; continue; }
		if (depth[c] < depth[d]) { int tmp = d; d = c; c = tmp; }
		cout << find_parent(c, d) << "\n";
	}
	return 0;
}

