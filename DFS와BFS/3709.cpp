#include <iostream>
#include <cstring>
using namespace std;
int N, M, T, a, b, direction;
int Map[52][52];
bool visit[52][52][4];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };//¼­ºÏµ¿³²
pair<int, int>raser;
void dfs(int x, int y, int d)
{
    if (visit[y][x][d]) { cout << "0\n"; return; }
    if (x == 0 || x == N + 1 || y == 0 || y == N + 1) {
        cout << y << " " << x << "\n";
        return;
    }
    visit[y][x][d] = true;
    if (Map[y][x] == 1)d = (d + 1) % 4;
    dfs(x + dx[d], y + dy[d], d);
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N >> M; memset(Map, 0, sizeof(Map)); memset(visit, false, sizeof(visit));
        for (int i = 0; i < M; i++) { cin >> a >> b; Map[a][b] = 1; }
        cin >> raser.second >> raser.first;
        if (raser.first == 0)direction = 2; else if (raser.first == N + 1)direction = 0;
        else if (raser.second == 0)direction = 3; else direction = 1;
        visit[raser.second][raser.first][direction] = true;
        dfs(raser.first + dx[direction], raser.second + dy[direction], direction);
    }
}