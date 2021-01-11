#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<int>* v;
bool* pos;
void bfs(int num)
{
	queue<int>q;
	q.push(num);
	pos[num] = true;
	while (!(q.empty()))
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++)
			if (!pos[v[x][i]])
			{
				q.push(v[x][i]);
				pos[v[x][i]] = true;
			}
	}
}
void dfs(int num)
{
	pos[num] = true;
	printf("%d ", num);
	for (int i = 0; i < v[num].size(); i++)if (!pos[v[num][i]])dfs(v[num][i]);
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, start;
	cin >> n >> m >> start;	
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
	dfs(start);
	memset(pos, false, sizeof(bool) * (n + 1));
	printf("\n");
	bfs(start);
	return 0;
}