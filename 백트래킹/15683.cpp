#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, Map[8][8], result = 1e9;
vector<pair<int, int>>v;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
bool range(int x,int y)
{
    if (x < 0 || x >= M || y < 0 || y >= N || Map[y][x] == 6)return false;
    return true;
}
void checkMap(int x, int y, int d)
{
    int nextX = x + dx[d], nextY = y + dy[d];
    while (range(nextX, nextY)) {
        if (Map[nextY][nextX] == 0)Map[nextY][nextX] = 7;
        nextX += dx[d], nextY += dy[d];
    }
}
void solve(int num)
{
    if (num == v.size()) {
        int sum = 0;
        for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == 0)sum++;
        result = min(result, sum);
        return;
    }
    int x = v[num].first, y = v[num].second, type = Map[y][x];
    if (type == 1) {
        for (int i = 0; i < 4; i++) {
            int backUp[8][8]; memcpy(backUp, Map, sizeof(Map));
            checkMap(x, y, i);
            solve(num + 1);
            memcpy(Map, backUp, sizeof(Map));
        }
    }
    else if (type == 2) {
        for (int i = 0; i < 2; i++) {
            int backUp[8][8]; memcpy(backUp, Map, sizeof(Map));
            checkMap(x, y, i); checkMap(x, y, i + 2);
            solve(num + 1);
            memcpy(Map, backUp, sizeof(Map));
        }
    }
    else if (type == 3) {
        for (int i = 0; i < 4; i++) {
            int backUp[8][8]; memcpy(backUp, Map, sizeof(Map));
            checkMap(x, y, i); checkMap(x, y, (i + 1) % 4);
            solve(num + 1);
            memcpy(Map, backUp, sizeof(Map));
        }
    }
    else if (type == 4) {
        for (int i = 0; i < 4; i++) {
            int backUp[8][8]; memcpy(backUp, Map, sizeof(Map));
            checkMap(x, y, i); checkMap(x, y, (i + 1) % 4); checkMap(x, y, (i + 2) % 4);
            solve(num + 1);
            memcpy(Map, backUp, sizeof(Map));
        }
    }
    else {
        int backUp[8][8]; memcpy(backUp, Map, sizeof(Map));
        checkMap(x, y, 0); checkMap(x, y, 1); checkMap(x, y, 2); checkMap(x, y, 3);
        solve(num + 1);
        memcpy(Map, backUp, sizeof(Map));
    }
    
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j]; if (Map[i][j] != 0 && Map[i][j] != 6)v.push_back({ j,i });
    }
    solve(0);
    cout << result;
}