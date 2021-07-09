#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, cnt;
char Map[1000][1001];
bool l[1001][1001], r[1001][1001], t[1001][1001], b[1001][1001];
bool range(int x, int y) { if (x < 0 || x >= M || y < 0 || y >= N)return false; return true; }
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)cin >> Map[i];
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] == 'X' || Map[i + 1][j] == 'X')continue;
            if (j != 0) {
                if (Map[i][j - 1] == 'X' && Map[i + 1][j - 1] == 'X') {
                    if (!l[i][j - 1] && !l[i + 1][j - 1]) {
                        l[i][j - 1] = true; l[i + 1][j - 1] = true; cnt++;
                    }
                }
            }
            if (j != M - 1) {
                if (Map[i][j + 1] == 'X' && Map[i + 1][j + 1] == 'X') {
                    if (!r[i][j + 1] && !r[i + 1][j + 1]) {
                        r[i][j + 1] = true; r[i + 1][j + 1] = true; cnt++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (Map[i][j] == 'X' || Map[i][j + 1] == 'X')continue;
            if (i != 0) {
                if (Map[i - 1][j] == 'X' && Map[i - 1][j + 1] == 'X') {
                    if (!t[i - 1][j] && !t[i - 1][j + 1]) {
                        t[i - 1][j] = true; t[i - 1][j + 1] = true; cnt++;
                    }
                }
            }
            if (i != N - 1) {
                if (Map[i + 1][j] == 'X' && Map[i + 1][j + 1] == 'X') {
                    if (!b[i + 1][j] && !b[i + 1][j + 1]) {
                        b[i + 1][j] = true; b[i + 1][j + 1] = true; cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;
}