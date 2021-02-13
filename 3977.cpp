#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int>* v; vector<int>* rv;
bool visit[100001], degree[100001];
vector<int>* scc;
int scc_val[100001];
stack<int>s;
void dfs(int c) { visit[c] = true; for (int n : v[c])if (!visit[n]) dfs(n); s.push(c);}
void r_dfs(int c, int r) { visit[c] = true; scc_val[c] = r; scc[r].push_back(c); for (int n : rv[c])if (!visit[n]) r_dfs(n, r); }
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, n, m, a, b; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int cnt = 0, check = 0;
		cin >> n >> m; v = new vector<int>[n]; rv = new vector<int>[n]; memset(visit, false, sizeof(visit));
		for (int j = 0; j < m; j++) { cin >> a >> b; v[a].push_back(b); rv[b].push_back(a); }
		for (int j = 0; j < n; j++)if (!visit[j])dfs(j);
		memset(visit, false, sizeof(visit)); memset(degree, false, sizeof(degree)); scc = new vector<int>[n];
		memset(scc_val, 0, sizeof(scc_val));
		while (!s.empty())
		{
			int cur = s.top(); s.pop();
			if (visit[cur])continue;
			r_dfs(cur, cnt); cnt++;
		}
		for (int j = 0; j < n; j++)for (int k : v[j])if (scc_val[j] != scc_val[k]) { degree[scc_val[k]] = true;}
		for (int j = 0; j < cnt; j++)if (!degree[j])check++;
		if (check != 1) { cout << "Confused\n\n"; continue; }
		for (int j = 0; j < cnt; j++)
		{
			if (degree[j]) { continue; }
			sort(scc[j].begin(), scc[j].end());
			int len = scc[j].size(); 
			for (int k = 0; k < len; k++)cout << scc[j][k] << "\n";
		}
		cout << "\n";
	}
}