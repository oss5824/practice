#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, Map[13][13];
pair<pair<int, int>, int>info[11];
vector<int>v[13][13];
int dx[5] = { 0,1,-1,0,0 }, dy[5] = { 0,0,0,-1,1 };
bool check = false;
bool range(int x, int y) { if (x <= 0 || x > N || y <= 0 || y > N || Map[y][x] == 2)return false; return true; }
void move(int i)
{
    int x = info[i].first.first, y = info[i].first.second, d = info[i].second;
    int nx = x + dx[d], ny = y + dy[d], nd = 0;
    if (!range(nx, ny)) {
        if (d == 1)nd = 2; else if (d == 2)nd = 1; else if (d == 3)nd = 4; else nd = 3;
        info[i].second = nd;
        nx = x + dx[nd]; ny = y + dy[nd];
        if (!range(nx, ny))return;
        else move(i);
    }
    else if (Map[ny][nx] == 0) {
        vector<int>tmp;
        int len = v[y][x].size();
        for (int k = 0; k < len; k++) {
            if (v[y][x][k] == i) { while (k < len)tmp.push_back(v[y][x][k++]); }
        }
        for (int k = 0; k < tmp.size(); k++) {
            v[y][x].pop_back(); info[tmp[k]].first = { nx,ny }; v[ny][nx].push_back(tmp[k]);
        }
    }
    else {
        vector<int>tmp;
        int len = v[y][x].size();
        for (int k = 0; k < len; k++) {
            if (v[y][x][k] == i) { while (k < len)tmp.push_back(v[y][x][k++]); }
        }
        reverse(tmp.begin(), tmp.end());
        for (int k = 0; k < tmp.size(); k++) {
            v[y][x].pop_back(); info[tmp[k]].first = { nx,ny }; v[ny][nx].push_back(tmp[k]);
        }
    }
    if (v[ny][nx].size() >= 4)check = true;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)cin >> Map[i][j];
    for (int i = 1; i <= K; i++) {
        int a, b, c; cin >> a >> b >> c; info[i] = { {b,a},c }; v[a][b].push_back(i);
    }
    for (int T = 1; T <= 1000; T++) {
        for (int i = 1; i <= K; i++) { move(i); if (check) { cout << T; return 0; } }
    }
    cout << "-1";
}