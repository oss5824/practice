#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, lv[1001], sem[1001];
vector<int>v[1001];
queue<int>q;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b; lv[b]++; v[a].push_back(b);
    }for (int i = 1; i <= N; i++)if (lv[i] == 0)q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int nx : v[x]) {
            if (--lv[nx] == 0) {
                q.push(nx); if (sem[x] + 1 > sem[nx])sem[nx] = sem[x] + 1;
            }
        }
    }for (int i = 1; i <= N; i++)cout << sem[i] + 1 << " ";
}


/*
#include <iostream>
#include <vector>
using namespace std;
int N, M, K, t;
vector<int>Map[401][401], smell[401][401];
vector<pair<int, pair<int, int>>>live;
int pHead[401], priority[5][5][401]; //priority 어디봤을 때, 우선 순위 순서, 누군지
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1, a; j <= N; j++) {
            cin >> a; if (a != 0)live.push_back({ a,{j,i} });
            Map[i][j].push_back(a); smell[i][j].push_back(a);
        }
    for (int i = 1; i <= M; i++)cin >> pHead[i];
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                cin >> priority[j][k][i];
            }
        }
    }
    while (1) {

        for (pair<int, pair<int, int>>p : live) {
            int num = p.first, x = p.second.first, y = p.second.second, d = pHead[num];
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)if (Map[i][j].size() == 1)cnt++;
        if (cnt == 1) { cout << t; return; }t++;
        if (t == 1000) { cout << "-1"; return; }
    }
}

*/