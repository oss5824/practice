#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, cut, point, a, sum, cnt, t;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> T >> point;
    vector<int>res; t = T;
    while (t--) {
        cin >> N >> cut;
        vector<int>v;
        for (int i = 0; i < N; i++) { cin >> a; v.push_back(a); }
        sort(v.begin(), v.end());
        while (!v.empty() && --cut)v.pop_back();
        if (v.empty())res.push_back(1);
        else res.push_back(v.back());
    }
    sort(res.begin(), res.end());
    while (cnt < T && sum + res[cnt] <= point)  sum += res[cnt++];
    cout << cnt;
}