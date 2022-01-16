#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, r;
pair<int, int>p[100000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0, a, b, c; i < N; i++) { cin >> a >> b >> c; p[i] = { b,c }; }
    sort(p, p + N);
    for (int i = 0; i < N; i++) {
        if (pq.empty())r++;
        else {
            if (pq.top().first <= p[i].first)pq.pop();
            else r++;
        }
        pq.push({ p[i].second,p[i].first });
    }cout << r;
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