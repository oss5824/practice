#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k, root[11][11], arr[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { 0,-1,1,1,-1,0,-1,1 };
queue<pair<pair<int, int>, int>>q;
vector<int>v[11][11];
vector<pair<int, int>>newTree;
void Tree(int x, int y)
{
	int len = v[y][x].size(), die = len;
	sort(v[y][x].begin(), v[y][x].end());
	for (int i = 0; i < len; i++)
	{
		int diff = arr[y][x] - v[y][x][i];
		if (diff >= 0)
		{
			arr[y][x] -= v[y][x][i];
			v[y][x][i] += 1;
		}
		else { die = i; break; }
	}//spring
	int sum = 0;

	for (int i = len - 1; i >= die; i--) { sum += v[y][x][i] / 2; v[y][x].pop_back(); }
	arr[y][x] += sum;
	//summer
	for (int i = 0; i < die; i++)
	{
		if (v[y][x][i] % 5 == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				int nextX = x + dx[j], nextY = y + dy[j];
				if (nextX <= 0 || nextX > n || nextY <= 0 || nextY > n)continue;
				newTree.push_back({ nextX,nextY });
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) { cin >> root[i][j]; arr[i][j] = 5; }
	int a, b, c;
	for (int i = 0; i < m; i++) { cin >> a >> b >> c; v[a][b].push_back(c); }
	while (k--)
	{
		newTree.clear();
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (v[i][j].size() != 0)Tree(j, i);
		for (pair<int, int>p : newTree) { v[p.second][p.first].push_back(1); }

		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)arr[i][j] += root[i][j];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)if (v[i][j].size() != 0)sum += v[i][j].size();
	cout << sum;
	return 0;
}