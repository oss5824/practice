#include<iostream>
#include<cstring>
using namespace std;
int n; int arr[17][17], cnt = 0;
void dfs(int x,int y,int r)
{
	if (x == n && y == n) { cnt++; return; }
	if (r == 0){
		if (x + 1 <= n && arr[y][x + 1] != 1)dfs(x + 1, y, 0);
		if (x + 1 <= n && y + 1 <= n && arr[y][x + 1] != 1&& arr[y + 1][x + 1] != 1 && arr[y + 1][x] != 1) {
			dfs(x + 1, y + 1, 2);
		}
	}
	else if (r == 1) {
		if (y + 1 <= n && arr[y + 1][x] != 1)dfs(x, y + 1, 1);
		if (x + 1 <= n && y + 1 <= n && arr[y][x + 1] != 1 && arr[y + 1][x + 1] != 1 && arr[y + 1][x] != 1) {
			dfs(x + 1, y + 1, 2);
		}
	}
	else if (r == 2) {
		if (x + 1 <= n && arr[y][x + 1] != 1)dfs(x + 1, y, 0);
		if (y + 1 <= n && arr[y + 1][x] != 1)dfs(x, y + 1, 1);
		if (x + 1 <= n && y + 1 <= n && arr[y][x + 1] != 1 && arr[y + 1][x + 1] != 1 && arr[y + 1][x] != 1) {
			dfs(x + 1, y + 1, 2);
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; memset(arr, 1, sizeof(arr));
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> arr[i][j];
	dfs(2, 1, 0); cout << cnt;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);