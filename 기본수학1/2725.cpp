#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int arr[1001];
int gcd(int a, int b)
{
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int n, m; cin >> n;
    set<pair<int, int>>s;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            int gcdNum = gcd(i, j);
            s.insert({ j / gcdNum,i / gcdNum });
        }
        arr[i] = 2 * s.size();
    }
    while (n--) {
        cin >> m;
        cout << arr[m] + 3 << "\n";
    }
}