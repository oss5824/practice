#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
typedef unsigned long long ull;
#define INF INT_MAX
using namespace std;
int N, M, K, Map[300][300], backUp[300][300];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	while (K--)
	{
		memcpy(backUp, Map, sizeof(Map));
		int sx = 0, sy = 0, ex = M - 1, ey = N - 1;
		while (sx < ex && sy < ey)
		{
			for (int i = sx; ex > i; i++)Map[sy][i] = backUp[sy][i + 1];
			for (int i = ey; i > sy; i--)Map[i][sx] = backUp[i - 1][sx];
			for (int i = ex; sx < i; i--)Map[ey][i] = backUp[ey][i - 1];
			for (int i = sy; i < ey; i++)Map[i][ex] = backUp[i + 1][ex];
			sx++; sy++; ex--; ey--;
		}
	}
	for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++)cout << Map[i][j] << " "; cout << "\n"; }
	return 0;
}
