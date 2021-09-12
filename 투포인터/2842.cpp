#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
string Map[50];
int height[50][50];
bool visit[50][50];
int n, sx, sy, cnt, res = 1e9;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,-1,-1,-1,0,1,1,1 };
vector<int>v;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Map[i];
        for (int j = 0; j < n; j++) {
            if (Map[i][j] == 'P')  sx = j, sy = i;
            else if (Map[i][j] == 'K')cnt++;
        }
    }
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> height[i][j], v.push_back(height[i][j]);
    sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
    int minH = 0, maxH = 0, sz = v.size();

    while (minH < sz && maxH < sz) {
        queue<pair<int, int>>q; q.push({ sx,sy }); memset(visit, false, sizeof(visit));
        visit[sy][sx] = true;
        int inCnt = 0;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            if (height[y][x]<v[minH] || height[y][x]>v[maxH])continue;
            if (Map[y][x] == 'K')inCnt++;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[ny][nx])continue;
                q.push({ nx,ny }); visit[ny][nx] = true;
            }
        }
        if (inCnt == cnt) res = min(res, v[maxH] - v[minH]), minH++;
        else maxH++;
    }
    cout << res;
}