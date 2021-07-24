#include<iostream>
#include<algorithm>
using namespace std;
int Map[700][700], M, N, a, b, c, idx;
int sum[3];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < N; i++){
		int x = 0, y = M - 1; cin >> a >> b >> c;
		while (a != 0) { if (y == 0)x++; else if (x == 0)y--; a--; }
		while (b != 0) { Map[y][x] += 1; if (y == 0)x++; else if (x == 0)y--; b--; }
		while (c != 0) { Map[y][x] += 2; if (y == 0)x++; else if (x == 0)y--; c--; }
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (j == 0)idx = i; else idx = 0;
			cout << Map[idx][j] + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}
