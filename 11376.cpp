#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int>v[1001];
int arr[1001];
bool visit[1001];
bool dfs(int num)
{
	for (int work : v[num])
	{
		if (visit[work] == true)continue;
		visit[work] = true;
		if (arr[work] == 0 || dfs(arr[work])) { arr[work] = num; return true; }
	}
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, k, a, res = 0; cin >> n >> m;
	for (int i = 1; i <= n; i++) { cin >> k; for (int j = 0; j < k; j++) { cin >> a; v[i].push_back(a); } }
	for (int i = 1; i <= n; i++) { memset(visit, false, sizeof(visit)); if (dfs(i))res++; memset(visit, false, sizeof(visit)); if (dfs(i))res++; }
	cout << res;
	return 0;
}