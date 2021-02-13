#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int>*v;
vector<int>*rv;
bool visit[100001], degree[100001];
int ssc[100001];
stack<int>s;
void dfs(int cur) { visit[cur] = true; for (int next : v[cur])if (!visit[next])dfs(next); s.push(cur); }
void reverse_dfs(int c, int r) { visit[c] = true; ssc[c] = r; for (int n : rv[c])if (!visit[n])reverse_dfs(n, r); }
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, n, m, a, b; cin >> T;
	for (int q = 0; q < T; q++)
	{
		cin >> n >> m; int res = 0, cnt = 0; memset(visit, false, sizeof(visit)); memset(ssc, 0, sizeof(ssc));
		memset(degree, false, sizeof(degree)); v = new vector<int>[n + 1]; rv = new vector<int>[n + 1];
		for (int i = 0; i < m; i++) { cin >> a >> b; v[a].push_back(b); rv[b].push_back(a); }
		for (int i = 1; i <= n; i++)if (!visit[i]) dfs(i);memset(visit, false, sizeof(visit));
		while (!s.empty())
		{
			int cur = s.top(); s.pop();
			if (visit[cur])continue;
			reverse_dfs(cur, res); res++;
		}
		for (int i = 1; i <= n; i++)for (int j : v[i])if (ssc[i] != ssc[j])degree[ssc[j]] = true;
		for (int i = 0; i < res; i++)if (!degree[i])cnt++;
		cout << cnt << "\n";
	}
	return 0;
}