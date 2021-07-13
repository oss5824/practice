#include <iostream>
#include <algorithm>
using namespace std;
int T, N, M, arr1[20000], arr2[20000];
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)cin >> arr1[i];
        for (int i = 0; i < M; i++)cin >> arr2[i];
        sort(arr2, arr2 + M);
        int sum = 0;
        for (int i = 0; i < N; i++)sum += (lower_bound(arr2, arr2 + M, arr1[i]) - arr2);
        cout << sum << "\n";
    }
}