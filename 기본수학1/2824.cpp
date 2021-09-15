#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#define INF 1000000000
using namespace std;
int arr1[32001], arr2[32001];
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int n; cin >> n;
    map<int, pair<int, int>>m;
    for (int i = 0, a; i < n; i++) {
        cin >> a;        
        for (int j = 2; j * j <= a; j++) { while (a % j == 0) { arr1[j]++; a /= j; } }
        if (a > 1 && a <= 32000)arr1[a]++;
        else m[a].first++;
    }
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        for (int j = 2; j * j <= a; j++) { while (a % j == 0) { arr2[j]++; a /= j; } }
        if (a > 1 && a <= 32000)arr2[a]++;
        else m[a].second++;
    }
    unsigned long long result = 1;
    bool add = false;
    for (int i = 2; i <= 32000; i++) {
        int count = min(arr1[i], arr2[i]);
        for (int j = 0; j < count; j++) {
            result = result * i;
            if (result >= INF) { add = true; result %= INF; }
        }
    }
    for (pair<int, pair<int, int>>p : m) {
        int count = min(p.second.first, p.second.second);
        for (int j = 0; j < count; j++) {
            result = result * p.first;
            if (result >= INF) { add = true; result %= INF; }
        }
    }
    if (add) {
        string s = to_string(result);
        while (s.length() != 9)s = '0' + s;
        cout << s;
    }
    else cout << result;
}