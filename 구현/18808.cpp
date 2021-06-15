#include<iostream>
#include<cstring>
#define INF 1e9
using namespace std;
int N, M, K;
bool Map[40][40], Sticker[100][10][10];
pair<int, int>posSticker[100];
bool moveSticker(int num)
{
	int x = posSticker[num].first, y = posSticker[num].second;
	for (int i = 0; i <= N - y; i++) {
		for (int j = 0; j <= M - x; j++) {
			bool check = false;
			for (int b = 0; b < y; b++) {
				for (int a = 0; a < x; a++) {
					if (Sticker[num][b][a]) {
						if (Map[i + b][j + a]) { check = true; break; }
					}
				}
				if (check)break;
			}
			if (!check) {
				for (int b = 0; b < y; b++)
					for (int a = 0; a < x; a++)if (Sticker[num][b][a])Map[i + b][j + a] = true;
				return true;
			}
		}
	}
	return false;
}
void solve(int num)
{
	int sx = 0, sy = 0;
	for (int k = 0; k < 4; k++) {
		if (moveSticker(num))return;

		int x = posSticker[num].first, y = posSticker[num].second;
		posSticker[num] = { y,x };
		bool backUp[10][10]; memcpy(backUp, Sticker[num], sizeof(backUp));
		for (int i = 0; i < x; i++)for (int j = 0; j < y; j++)Sticker[num][i][y - 1 - j] = backUp[j][i];
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		int n, m; cin >> n >> m;
		posSticker[k].second = n, posSticker[k].first = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int a; cin >> a; if (a == 1)Sticker[k][i][j] = true;
			}
	}
	for (int i = 0; i < K; i++) solve(i);

	int cnt = 0;

	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j])cnt++;
	cout << cnt << "\n";
	return 0;
}


