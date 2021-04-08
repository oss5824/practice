#include<iostream>
using namespace std;
int n, arr[101][101];
long long M[101][101];
long long dfs(int x,int y)
{
	if (x == n && y == n)return 1;
	if (arr[y][x] == 0)return 0;
	if (M[y][x] != 0)return M[y][x];
	int move_x = x + arr[y][x], move_y = y + arr[y][x];
	if (1 <= move_x && move_x <= n)M[y][x] += dfs(move_x, y);
	if (1 <= move_y && move_y <= n)M[y][x] += dfs(x, move_y);
	return M[y][x];
}
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> arr[i][j];
	cout << dfs(1, 1);
	return 0;
}