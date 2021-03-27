#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
bool Map[101][101];
int N;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
int x, y, direction;
stack<int>saveStack;
void Curve(int x, int y, int direction, int curve)
{
	Map[y][x] = true; saveStack.push(direction);
	x = x + dx[direction]; y = y + dy[direction];
	Map[y][x] = true;
	for (int i = 1; i <= curve; i++)
	{
		stack<int>useStack = saveStack;
		for (int j = 0; j < (int)pow(2, i - 1); j++)
		{
			direction = useStack.top(); useStack.pop();
			direction = ( direction== 3) ? 0 : direction + 1;
			x = x + dx[direction]; y = y + dy[direction];
			Map[y][x] = true;
			saveStack.push(direction);
		}
	}
}
void Square()
{
	int sum = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (Map[i][j] && Map[i][j + 1] && Map[i + 1][j] && Map[i + 1][j + 1])sum++;
	cout << sum;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, direction, curve;
		cin >> x >> y >> direction >> curve;
		Curve(x, y, direction, curve);
	}
	Square();
	return 0;
}
