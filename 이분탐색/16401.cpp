#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[1000000], res;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M; for (int i = 0; i < M; i++)cin >> arr[i];
    sort(arr, arr + M);
    int s = 1, e = arr[M - 1];
    while (s <= e) {
        int m = (s + e) / 2;
        int sum = 0;
        for (int i = 0; i < M; i++)sum += arr[i] / m;
        if (sum >= N) { res = max(res, m); s = m + 1; }
        else e = m - 1;
    }
    cout << res;
}