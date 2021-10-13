#include<iostream>
#include<queue>
using namespace std;
int N, M, Map[2000][2000], cnt;
bool visit[2000][2000][4];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };//¼­ºÏµ¿³²
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M; 
    queue<pair<pair<int, int>, int>>q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j]; 
            if (Map[i][j] == 9) {
                for (int k = 0; k < 4; k++)q.push({ {j,i},k }), visit[i][j][k] = true;
            }
        }
    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second, d = q.front().second; q.pop();
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || visit[ny][nx][d])continue;
        visit[ny][nx][d] = true;
        if (Map[ny][nx] == 0)q.push({ {nx,ny},d });
        else if (Map[ny][nx] == 1) {
            q.push({ { nx,ny }, (d + 2) % 4 }); visit[ny][nx][(d + 2) % 4] = true;
            if (d == 1 || d == 3)q.push({ { nx,ny }, d });
        }
        else if (Map[ny][nx] == 2) {
            q.push({ { nx,ny }, (d + 2) % 4 }); visit[ny][nx][(d + 2) % 4] = true;
            if (d == 0 || d == 2)q.push({ { nx,ny }, d });
        }
        else if (Map[ny][nx] == 3) {
            if (d == 0)d = 3; else if (d == 1)d = 2; else if (d == 2)d = 1; else d = 0;
            q.push({ { nx,ny }, d });
        }
        else if (Map[ny][nx] == 4){
            if (d == 0)d = 1; else if (d == 1)d = 0; else if (d == 2)d = 3; else d = 2;
            q.push({ { nx,ny }, d });
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (visit[i][j][0] == true || visit[i][j][1] == true ||
                visit[i][j][2] == true || visit[i][j][3] == true)cnt++;
        }
    cout << cnt;
}