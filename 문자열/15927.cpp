#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    string s; cin >> s;
    int len = s.length();
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (rev != s)cout << len;
    else {
        for (int i = 0; i < len - 1; i++)if (s[i] != s[i + 1]) { cout << len - 1 << "\n"; return 0; }
        cout << "-1";
    }
}