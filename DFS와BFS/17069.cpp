#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF ull_MAX
#define MAX 4000
typedef unsigned long long ull;
using namespace std;
ull N, M,cnt;
ull arr[33][33], Cache[33][33][3];
ull dfs(ull x, ull y, ull r)
{
	if (x > N || y > N)return 0;
	if (r == 0 || r == 1) { if (arr[y][x] == 1)return 0; }
	else if (r == 2) { if (arr[y][x] == 1 || arr[y][x - 1] == 1 || arr[y - 1][x] == 1)return 0; }
	if (x == N && y == N) { return 1; }
	if (Cache[y][x][r] != 0)return Cache[y][x][r];
	if (r == 0) Cache[y][x][0] = dfs(x + 1, y, 0) + dfs(x + 1, y + 1, 2);
	else if (r == 1) Cache[y][x][1] = dfs(x, y + 1, 1) + dfs(x + 1, y + 1, 2);
	else if (r == 2) Cache[y][x][2] = dfs(x + 1, y, 0) + dfs(x, y + 1, 1) + dfs(x + 1, y + 1, 2);
	return Cache[y][x][r];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; memset(arr, 1, sizeof(arr));
	for (ull i = 1; i <= N; i++)for (ull j = 1; j <= N; j++)cin >> arr[i][j];
	cout << dfs(2, 1, 0) << "\n";
	return 0;
}