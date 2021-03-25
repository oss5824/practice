#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, arr[1001][1001], M[1001][1001];
int cal(int x, int y)
{
	if (x == 0 || y == 0)return 0;
	if (x == 1 && y == 1)return arr[y][x];
	if (M[y][x] != -1)return M[y][x];
	M[y][x] = max(max(cal(x, y - 1), cal(x - 1, y)), cal(x - 1, y - 1)) + arr[y][x];
	return M[y][x];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	cin >> n >> m; memset(M, -1, sizeof(M));
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];
	cout << cal(m, n);
	return 0;
}

