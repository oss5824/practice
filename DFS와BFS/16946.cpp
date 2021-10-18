#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
int N, M, cnt;
string s[1000];
int Map[1000][1000];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int mapping[500001];
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> s[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i][j] == '1' || Map[i][j] != 0)continue;
			queue<pair<int, int>>q; q.push({ j,i }); Map[i][j] = ++cnt;
			int sum = 1;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second; q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N || s[ny][nx] == '1' || Map[ny][nx] != 0)continue;
					Map[ny][nx] = cnt; q.push({ nx,ny }); sum++;
				}
			}mapping[cnt] = sum;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i][j] == '0')cout << "0";
			else {
				int sum = 1; unordered_set<int>set;
				for (int k = 0; k < 4; k++) {
					int x = j + dx[k], y = i + dy[k];
					if (x < 0 || x >= M || y < 0 || y >= N || s[y][x] == '1' || set.count(Map[y][x]) == 1)continue;
					sum += mapping[Map[y][x]]; set.insert(Map[y][x]);
				}cout << sum % 10;
			}
		}cout << "\n";
	}
}