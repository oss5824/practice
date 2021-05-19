#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int Map[8][8],N;
int x_1, y_1, x_2, y_2;
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2 >> N;
	x_1 = s1[0] - 'A'; y_1 = s1[1] - '1';
	x_2 = s2[0] - 'A'; y_2 = s2[1] - '1';
	while (N--)
	{
		string s; cin >> s;
		int direction = 0;
		if (s == "R")direction = 6; else if (s == "L")direction = 1;
		else if (s == "B")direction = 3; else if (s == "T")direction = 4;
		else if (s == "RT")direction = 7; else if (s == "LT")direction = 2;
		else if (s == "RB")direction = 5; else if (s == "LB")direction = 0;
		int nextX = x_1 + dx[direction], nextY = y_1 + dy[direction];
		if (nextX < 0 || nextX >= 8 || nextY < 0 || nextY >= 8)continue;
		if (nextX == x_2 && nextY == y_2)
		{
			int nextx_2 = x_2 + dx[direction], nexty_2 = y_2 + dy[direction];
			if (nextx_2 < 0 || nextx_2 >= 8 || nexty_2 < 0 || nexty_2 >= 8)continue;
			x_2 = nextx_2; y_2 = nexty_2;
		}
		x_1 = nextX; y_1 = nextY;
	}
	cout << (char)(x_1 + 'A') << (char)(y_1 + '1') << "\n";
	cout << (char)(x_2 + 'A') << (char)(y_2 + '1') << "\n";
	return 0;
}