#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
int n, m, a, b, cnt;
vector<int>v[10001]; vector<int>rv[10001]; vector<int>ssc[10001];
bool visit[10001];
stack<int>s;
bool cmp(vector<int>a, vector<int>b) { return a[0] < b[0]; }
void dfs(int val)
{
	visit[val] = true;
	for (int next : v[val])if (!visit[next])dfs(next);
	s.push(val);
}
void reverse_dfs(int val, int num)
{
	visit[val] = true; ssc[num].push_back(val);
	for (int next : rv[val])if (!visit[next]) { reverse_dfs(next, num); }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) { cin >> a >> b; v[a].push_back(b); rv[b].push_back(a); }
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; i++)if (!visit[i])dfs(i);
	memset(visit, false, sizeof(visit));
	while (!s.empty())
	{
		int val = s.top(); s.pop();
		if (visit[val])continue;
		reverse_dfs(val, cnt); cnt = cnt + 1;
	}
	cout << cnt << "\n";
	vector<pair<int, int>>p;
	for (int i = 0; i < cnt; i++) { sort(ssc[i].begin(), ssc[i].end()); p.push_back({ ssc[i][0],i }); }
	sort(p.begin(), p.end());
	for (int i = 0; i < cnt; i++)
	{
		int idx = p[i].second;
		int len = ssc[idx].size();
		for (int j = 0; j < len; j++)cout << ssc[idx][j] << " ";
		cout << "-1\n";
	}
	return 0;
}