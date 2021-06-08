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
#define INF long long_MAX
typedef long long ll;
using namespace std;
int N, M, K, Map[16][16];
int endX = 0, endY = 0;
ll Cache[16][16];
long long dfs(int x, int y)
{
	if (x < endX || y < endY)return 0;
	if (x == endX && y == endY)return 1;
	if (Cache[y][x] != 0)return Cache[y][x];
	Cache[y][x] = dfs(x - 1, y) + dfs(x, y - 1);
	return Cache[y][x];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	long long cnt = 0;
	cin >> N >> M; for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)Map[i][j] = ++cnt;
	cin >> K;
	if (K == 0 || K == cnt || K == 1)cout << dfs(M - 1, N - 1);
	else {
		K--;
		memset(Cache, 0, sizeof(Cache));
		int startX = K % M, startY = K / M;
		long long val1 = dfs(startX, startY);
		memset(Cache, 0, sizeof(Cache));
		endX = startX, endY = startY;
		long long val2 = dfs(M - 1, N - 1);
		cout << val1 * val2;
	}
	return 0;
}


