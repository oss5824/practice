#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, par[1001], res;
bool power[1001];
vector<pair<int, pair<int, int>>>v;
int find(int x)
{
    if (par[x] == x)return x;
    else return par[x] = find(par[x]);
}
void merge(int a, int b)
{
    a = find(par[a]), b = find(par[b]);
    if (a == b)return;
    if (power[a] && power[b])return;
    if (power[a])par[b] = a;
    else if (power[b])par[a] = b;
    else if (a < b)par[a] = b;
    else par[b] = a;
}
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)par[i] = i;
    for (int i = 0, a; i < K; i++) {
        cin >> a; power[a] = true;
    }
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c; v.push_back({ c,{a,b} });
    }
    sort(v.begin(), v.end());
    for (pair<int, pair<int, int>>p : v) {
        int a = p.second.first, b = p.second.second, c = p.first;
        a = find(par[a]); b = find(par[b]);
        if (a == b || (power[a] && power[b]))continue;
        res += c;
        merge(a, b);
    }cout << res;
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