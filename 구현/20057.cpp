#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, Map[500][500];
int dx[4][9] = { { -2,-1,-1,0,0,0,0,1,1 },{0,-1,1,-2,-1,1,2,-1,1}
				,{2,1,1,0,0,0,0,-1,-1},{ 0,-1,1,-2,-1,1,2,-1,1 } };
int dy[4][9] = { { 0,-1,1,-2,-1,1,2,-1,1 },{-2,-1,-1,0,0,0,0,1,1}
			,{0,-1,1,-2,-1,1,2,-1,1},{2, 1, 1, 0, 0, 0, 0, -1, -1} };
int dx2[4] = { -1,0,1,0 };
int dy2[4] = { 0,-1,0,1 };
int arr[9] = { 5,10,10,2,7,7,2,1,1 };
//5 10 10 2 7 7 2 1 1
int result = 0;
bool range(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)return false;
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	int x = N / 2, y = N / 2, len = 1;
	bool check = false, fin = false;
	while (!(x <= 0 && y <= 0))
	{	
		int curX = x, curY = y, direction = 0;
		if (len % 2 == 1) { if (!check)direction = 0; else direction = 3; }
		else { if (!check)direction = 2; else direction = 1; }
		if (y == 0) { direction = 0; len--; fin = true; }
		for (int k = 1; k <= len; k++)
		{
			int sum = 0;
			curX = curX + dx2[direction], curY = curY + dy2[direction];
			int value = Map[curY][curX];
			int tmp = value;

			for (int i = 0; i < 9; i++)
			{
				int nextX = curX + dx[direction][i], nextY = curY + dy[direction][i];
				if (!range(nextX, nextY))result = result + (tmp * arr[i]) / 100;
				else Map[nextY][nextX] += (tmp * arr[i]) / 100;
				value = value - (tmp * arr[i]) / 100;
			}
			if (range(curX + dx2[direction], curY + dy2[direction])) {
				Map[curY + dy2[direction]][curX + dx2[direction]] += value;
			}
			else result = result + value;
			Map[curY][curX] = 0;
		}
		if (fin)break;
		x = curX, y = curY;
		if (check) { len++; check = false; }
		else  check = true;
	}
	cout << result;
	return 0;
}
