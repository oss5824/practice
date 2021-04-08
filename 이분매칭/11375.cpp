#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v[1001];
bool visit[1001];
int pos[1001];
bool dfs(int num)
{
	for (int work : v[num])
	{
		if (visit[work])continue;
		visit[work] = true;
		if (pos[work] == 0 || dfs(pos[work])) { pos[work] = num; return true; }
	}
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, k, a, res = 0; cin >> n >> m;
	for (int i = 1; i <= n; i++) { cin >> k; for (int j = 0; j < k; j++) { cin >> a; v[i].push_back(a); } }
	for (int i = 1; i <= n; i++) 
	{ memset(visit, false, sizeof(visit)); if (dfs(i))res++; }
	cout << res;
	return 0;
}