#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
char** arr;
int move_x[4] = { -1,1,0,0 }, move_y[4] = { 0, 0,-1,1 };
int n, result;
vector<int>res;
void bfs(int i, int j)
{
	queue<pair<int, int>>q;
	q.push({ i,j }); result = 1; arr[i][j] = '0';
	while (!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_y = y + move_y[i], next_x = x + move_x[i];
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)continue;
			if (arr[next_y][next_x] == '1')
			{
				arr[next_y][next_x] = '0';q.push({ next_y,next_x }); result++;
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a; cin >> n; arr = new char* [n];
	for (int i = 0; i < n; i++) arr[i] = new char[n]; 
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> arr[i][j];
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) if (arr[i][j]=='1') { bfs(i, j); res.push_back(result); }
	int len = res.size(); sort(res.begin(), res.end());
	cout << len; for (auto i : res)cout << "\n"<<i;
	return 0;
}