#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, v[100001];
bool check(int m)
{
    if (v[0] - m > 0)return false;
    for (int i = 1; i < M; i++) { if (v[i - 1] + m < v[i] - m)return false; }
    if (v[M - 1] + m < N)return false;
    return true;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++)cin >> v[i];
    int s = 0, e = N, result = 0, m = 0;
    while (s <= e) {
        m = (s + e) / 2;
        if (check(m)) { result = m; e = m - 1; }
        else s = m + 1;
    }
    cout << result;
}