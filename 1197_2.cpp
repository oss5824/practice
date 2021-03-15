#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, pair<int, int>>>v;
int par[10001], level[10001];
int find(int x) { if (par[x] == x)return x; else return par[x] = find(par[x]); }
bool merge(int x, int y)
{
	x = find(x), y = find(y); if (x == y)return false;
	if (level[x] > level[y]) swap(x, y);
	par[x] = y;
	if (level[x] == level[y])level[y]++;
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, c, res = 0; cin >> n >> m; for (int i = 1; i <= n; i++)par[i] = i;
	while(m--) { cin >> a >> b >> c; v.push_back({ c,{a,b} }); }
	sort(v.begin(), v.end());
	for (pair<int, pair<int, int>>p : v)
	{
		a = p.second.first, b = p.second.second;
		if (merge(a, b))res += p.first;
	}cout << res;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);