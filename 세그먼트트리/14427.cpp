#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int arr[100001], tree[400004], N, Q;

int getIdx(int a, int b)
{
    if (arr[a] == arr[b])return min(a, b);
    else if (arr[a] > arr[b])return b;
    else return a;
}
int init(int s, int e, int n)
{
    if (s == e)return tree[n] = s;
    int m = (s + e) / 2;
    return tree[n] = getIdx(init(s, m, 2 * n), init(m + 1, e, 2 * n + 1));
}
int update(int s, int e, int idx, int n)
{
    if (s > idx || e < idx || s == e)return tree[n];
    int m = (s + e) / 2;
    return tree[n] = getIdx(update(s, m, idx, 2 * n), update(m + 1, e, idx, 2 * n + 1));
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; for (int i = 1; i <= N; i++)cin >> arr[i];
    cin >> Q;
    arr[0] = 2e9;
    init(1, N, 1);
    while (Q--) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            arr[b] = c;
            update(1, N, b, 1);
        }
        else cout << tree[1] << "\n";
    }
}