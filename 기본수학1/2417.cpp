#include <iostream>
#include <limits.h>
#include <cmath>
typedef unsigned long long ull;
using namespace std;
ull N;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    if (N == 1 || N == 0) { cout << N; return 0; }
    ull s = 0, e = ceil(sqrt(LLONG_MAX)), val = 0;
    while (s <= e) {
        ull m = (s + e) / 2;
        ull res = m * m;
        if (N <= res) { val = m; e = m - 1; }
        else s = m + 1;
    }cout << val;
}