#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, Hx, Hy, Ex, Ey;
int Map[1001][1001], dp[1001][1001][2];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M >> Hy >> Hx >> Ey >> Ex;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> Map[i][j]; dp[i][j][0] = 1e9; dp[i][j][1] = 1e9;
        }

    queue<pair<pair<int, int>, bool>>q; q.push({ {Hx,Hy},0 });
    dp[Hy][Hx][0] = 0;
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        bool broken = q.front().second; q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx<1 || nx>M || ny<1 || ny>N)continue;
            if (Map[ny][nx] == 0) {
                if (dp[ny][nx][broken] > dp[y][x][broken] + 1) {
                    q.push({ {nx,ny},broken });
                    dp[ny][nx][broken] = dp[y][x][broken] + 1;
                }
            }
            else {
                if (broken)continue;
                else {
                    if (dp[ny][nx][1] > dp[y][x][0] + 1)
                    q.push({ {nx,ny},true });
                    dp[ny][nx][1] = dp[y][x][0] + 1;
                }
            }
        }
    }
    int result = min(dp[Ey][Ex][0], dp[Ey][Ex][1]);
    if (result == 1e9)result = -1; cout << result;
}