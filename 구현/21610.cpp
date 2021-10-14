#include<iostream>
#include<queue>
using namespace std;
int N, M, Map[51][51], d, s, res;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)cin >> Map[i][j];
    queue<pair<int, int>>q; q.push({ 1,N }); q.push({ 2,N }); q.push({ 1,N - 1 }); q.push({ 2,N - 1 });
    while (M--) {
        cin >> d >> s; d--;
        vector<pair<int, int>>v;
        bool check[51][51] = { false, };
        while (!q.empty()) {
            int y = q.front().second, x = q.front().first; q.pop();
            x = (x + s * dx[d]) % N; y = (y + s * dy[d]) % N;
            if (x <= 0)x += N; if (y <= 0)y += N;
            check[y][x] = true; v.push_back({ x,y }); Map[y][x]++;
        }
        int water[51][51] = { 0, };
        for (pair<int, int>p : v) {
            int x = p.first, y = p.second;
            for (int i = 1; i < 8; i += 2) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx<1 || nx>N || ny<1 || ny>N || Map[ny][nx] <= 0)continue;
                water[y][x]++;
            }
        }res = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                Map[i][j] += water[i][j];
                if (Map[i][j] >= 2 && check[i][j] == false) { q.push({ j,i }), Map[i][j] -= 2; }
                res += Map[i][j];
            }
        }
    } cout << res;
}