#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[10000], res;
int check(int m)
{
    int sum = 0;
    for (int i = 0; i < N; i++) { if (arr[i] <= m)sum += arr[i]; else sum += m; }
    return sum;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; for (int i = 0; i < N; i++)cin >> arr[i]; cin >> M;
    sort(arr, arr + N);
    int s = M / N, e = arr[N - 1], m;
    while (s <= e) {
        m = (s + e) / 2;
        if (check(m) <= M) { res = max(res, m); s = m + 1; }
        else e = m - 1;
    }
    cout << res;
}