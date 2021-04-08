#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>* v;
bool* pos;
int cnt = 0;
void dfs(int num)
{
	pos[num] = true;
	for (int i = 0; i < v[num].size(); i++)
		if (!pos[v[num][i]])
		{
			cnt++;
			dfs(v[num][i]);
		}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;	
	v = new vector<int>[n + 1];
	pos = new bool[n + 1];
	memset(pos, false, sizeof(bool) * (n + 1));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)sort(v[i].begin(), v[i].end());
	dfs(1);
	printf("%d", cnt);
	return 0;
}