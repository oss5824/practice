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
int N, M, K, Map[100][100], backUp[100][100];


void RotateGroupLeft()
{
	memcpy(backUp, Map, sizeof(Map));
	for (int i = 0; i < N / 2; i++)for (int j = 0; j < M / 2; j++)Map[i][j] = backUp[i][j + M / 2];
	for (int i = 0; i < N / 2; i++)for (int j = M / 2; j < M; j++)Map[i][j] = backUp[i + N / 2][j];
	for (int i = N / 2; i < N; i++)for (int j = 0; j < M / 2; j++)Map[i][j] = backUp[i - N / 2][j];
	for (int i = N / 2; i < N; i++)for (int j = M / 2; j < M; j++)Map[i][j] = backUp[i][j - M / 2];
}
void RotateGroupRight()
{
	memcpy(backUp, Map, sizeof(Map));
	for (int i = 0; i < N / 2; i++)for (int j = 0; j < M / 2; j++)Map[i][j] = backUp[i + N / 2][j];
	for (int i = 0; i < N / 2; i++)for (int j = M / 2; j < M; j++)Map[i][j] = backUp[i][j - M / 2];
	for (int i = N / 2; i < N; i++)for (int j = 0; j < M / 2; j++)Map[i][j] = backUp[i][j + M / 2];
	for (int i = N / 2; i < N; i++)for (int j = M / 2; j < M; j++)Map[i][j] = backUp[i - N / 2][j];
}
void RotateLeft()
{
	memcpy(backUp, Map, sizeof(Map));
	swap(N, M);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)Map[i][j] = backUp[j][N - i - 1];
}
void RotateRight()
{
	swap(N, M);
	memcpy(backUp, Map, sizeof(Map));
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)Map[i][j] = backUp[M - j - 1][i];
}
void LeftRight()
{
	for (int i = 0; i < M / 2; i++)for (int j = 0; j < N; j++)swap(Map[j][i], Map[j][M - 1 - i]);
}
void TopDown()
{
	for (int i = 0; i < N / 2; i++)for (int j = 0; j < M; j++)swap(Map[i][j], Map[N - 1 - i][j]);
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	while (K--)
	{
		int a; cin >> a;
		if (a == 1)TopDown();
		else if (a == 2)LeftRight();
		else if (a == 3)RotateRight();
		else if (a == 4)RotateLeft();
		else if (a == 5)RotateGroupRight();
		else if (a == 6)RotateGroupLeft();
	}
	for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++)cout << Map[i][j] << " "; cout << "\n"; }
	return 0;
}
