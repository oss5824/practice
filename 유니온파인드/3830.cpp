#include <iostream>
using namespace std;
int N, M, par[100001];
long long dist[100001];
int getPar(int x)
{
    if (x == par[x])return x;
    int parX = getPar(par[x]);
    dist[x] += dist[par[x]];
    return par[x] = parX;
}
void merge(int a, int b, long long d)
{
    int topA = par[a], topB = par[b];
    if (topA == topB)return;
    dist[topB] = dist[a] + d - dist[b]; par[topB] = topA;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    while (1) {
        cin >> N >> M; if (N == 0 && M == 0)break;
        for (int i = 0; i <= N; i++)par[i] = i, dist[i] = 0;
        while (M--) {
            char ch; int a, b; long long c; cin >> ch >> a >> b;
            getPar(a); getPar(b);
            if (ch == '!') { cin >> c; merge(a, b, c); }
            else par[a] != par[b] ? cout << "UNKNOWN\n" : cout << dist[b] - dist[a] << "\n";
        }
    }
}