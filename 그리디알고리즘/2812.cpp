#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int N, K;
string s;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> K >> s;
    int cnt = 0;
    string res;
    res.push_back(s[0]);
    for (int i = 1; i < N; i++) {
        while (!res.empty() && res.back() < s[i]) {
            cnt++; res.pop_back();
            if (cnt == K) { cout << res; string sub = s.substr(i); cout << sub; return 0; }
        }
        res.push_back(s[i]);
    }
    cout << res.substr(0, N - K);
}