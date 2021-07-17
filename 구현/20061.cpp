#include<iostream>
#define INF INT_MAX
using namespace std;

int N, green[6][4], blue[4][6];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	int score = 0, cnt = 0;
	while (N--) {
		int t, y, x; cin >> t >> y >> x;
		if (t == 1) {
			int start = 0;
			while (start < 6 && green[start][x] == 0) { start++; }
			green[--start][x] = 1; 

			start = 0;
			while (start < 6 && blue[y][start] == 0) start++;
			blue[y][--start] = 1;
		}
		else if (t == 2) {
			int start = 0;
			while (start < 6 && (green[start][x] == 0 && green[start][x + 1] == 0)) start++;
			start--;
			green[start][x] = 1; green[start][x + 1] = 1;

			start = 0;
			while (start < 6 && blue[y][start] == 0) start++;
			start--;
			blue[y][start] = 1; blue[y][start - 1] = 1;
		}
		else if (t == 3) {
			int start = 0;
			while (start < 6 && (blue[y][start] == 0 && blue[y + 1][start] == 0)) start++;
			start--; 
			blue[y][start] = 1; blue[y + 1][start] = 1;

			start = 0;
			while (start < 6 && green[start][x] == 0) start++;
			start--; 
			green[start][x] = 1; green[start - 1][x] = 1;
		}
		for (int i = 5; i > 0; i--) {
			if (green[i][0] == 1 && green[i][1] == 1 && green[i][2] == 1 && green[i][3] == 1) {
				for (int j = i; j > 0; j--) {
					green[j][0] = green[j - 1][0]; green[j][1] = green[j - 1][1];
					green[j][2] = green[j - 1][2]; green[j][3] = green[j - 1][3];
				}i++; score++;
			}
		}
		for (int i = 5; i > 0; i--) {
			if (blue[0][i] == 1 && blue[1][i] == 1 && blue[2][i] == 1 && blue[3][i] == 1) {
				for (int j = i; j > 0; j--) {
					blue[0][j] = blue[0][j - 1]; blue[1][j] = blue[1][j - 1];
					blue[2][j] = blue[2][j - 1]; blue[3][j] = blue[3][j - 1];
				}i++; score++;
			}
		}
		int green_cnt = 0, blue_cnt = 0;
		if (green[1][0] == 1 || green[1][1] == 1 || green[1][2] == 1 || green[1][3] == 1) {
			green_cnt++;
			if (green[0][0] == 1 || green[0][1] == 1 || green[0][2] == 1 || green[0][3] == 1) green_cnt++;		
			for (int k = 0; k < green_cnt; k++) {
				for (int i = 5; i > 0; i--) {
					green[i][0] = green[i - 1][0]; green[i][1] = green[i - 1][1];
					green[i][2] = green[i - 1][2]; green[i][3] = green[i - 1][3];
				}
				green[0][0] = 0; green[0][1] = 0; green[0][2] = 0; green[0][3] = 0;
			}
			green[1][0] = 0; green[1][1] = 0; green[1][2] = 0; green[1][3] = 0;
		}
		if (blue[0][1] == 1 || blue[1][1] == 1 || blue[2][1] == 1 || blue[3][1] == 1) {
			blue_cnt++;
			if (blue[0][0] == 1 || blue[1][0] == 1 || blue[2][0] == 1 || blue[3][0] == 1) blue_cnt++;
			for (int k = 0; k < blue_cnt; k++) {
				for (int i = 5; i > 0; i--) {
					blue[0][i] = blue[0][i - 1]; blue[1][i] = blue[1][i - 1];
					blue[2][i] = blue[2][i - 1]; blue[3][i] = blue[3][i - 1];
				}
				blue[0][0] = 0; blue[1][0] = 0; blue[2][0] = 0; blue[3][0] = 0;
			}
			blue[0][1] = 0; blue[1][1] = 0; blue[2][1] = 0; blue[3][1] = 0;
		}
	}
	for (int i = 0; i < 6; i++)for (int j = 0; j < 4; j++)if (green[i][j] == 1)cnt++;
	for (int i = 0; i < 4; i++)for (int j = 0; j < 6; j++)if (blue[i][j] == 1)cnt++;
	cout << score << "\n" << cnt;
	return 0;
}