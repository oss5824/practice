#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
vector<pair<int, int>>v[1001];
priority_queue<int>res[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
void bfs()
{
    q.push({ 0,1 }); res[1].push(0);
    while (!q.empty()) {
        int cost = q.top().first, cur = q.top().second; q.pop();
        for (pair<int, int>p : v[cur]) {
            int nextCost = cost + p.second, next = p.first;
            if (res[next].size() < K) { q.push({ nextCost,next }); res[next].push(nextCost); }
            else {
                if (res[next].top() > nextCost) { res[next].pop(); q.push({ nextCost,next }); res[next].push(nextCost); }
            }
        }
    }
}
int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M >> K; while (M--) { int a, b, c; cin >> a >> b >> c; v[a].push_back({ b,c }); }
    bfs();
    for (int i = 1; i <= N; i++)res[i].size() < K ? cout << "-1\n" : cout << res[i].top() << "\n";
}