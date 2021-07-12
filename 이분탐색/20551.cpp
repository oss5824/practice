#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int N, M, arr[200000], a;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)cin >> arr[i];
    sort(arr, arr + N);
    while (M--) {
        cin >> a;
        int s = 0, e = N - 1, idx = 0;
        while (s <= e) {
            int m = (s + e) / 2;
            if (arr[m] >= a) { idx = m; e = m - 1; }
            else s = m + 1;
        }
        idx = (arr[idx] == a) ? idx : -1;
        cout << idx << "\n";
    }
}