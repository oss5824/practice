#include<iostream>
#include<string>
#include<map>
using namespace std;
int N, M, K, len;
char Map[10][11];string s;
map<string, int>m;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dfs(int curX, int curY, int pos)
{
	if (pos == len - 1)return 1;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		int nextX = curX + dx[i], nextY = curY + dy[i], nextP = pos + 1;
		if (nextX == -1)nextX = M - 1; else if (nextX == M)nextX = 0;
		if (nextY == -1)nextY = N - 1; else if (nextY == N)nextY = 0;

		if (Map[nextY][nextX] == s[nextP])sum += dfs(nextX, nextY, nextP);
	}
	return sum;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> Map[i];
	while (K--) {
		cin >> s;
		if (m[s] == 0) {
			len = s.length(); int sum = 0;
			for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (s[0] == Map[i][j])sum += dfs(j, i, 0);
			m[s] = sum;
		}
		cout << m[s] << "\n";
	}
	return 0;
}