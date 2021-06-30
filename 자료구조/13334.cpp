#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int N, D;
vector<pair<int, int>>tmp, v;
bool cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.second == b.second)return a.first < b.first;
    else return a.second < b.second;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b; if (a > b)swap(a, b); tmp.push_back({ a,b });
    }
    cin >> D;
    for (int i = 0; i < N; i++) { if (tmp[i].second - tmp[i].first <= D)v.push_back(tmp[i]); }
    if (v.empty()) { cout << "0"; return 0; }
    sort(v.begin(), v.end(), cmp);
    int len = v.size();
    int cnt = 0, result = 0;
    priority_queue<int, vector<int>, greater<int>>q;
    for (int i = 0; i < len; i++) {
        int start = v[i].first, end = v[i].second;
        q.push(start);
        while (!q.empty()) {
            if (q.top() < end - D)q.pop();
            else { result = max(result, (int)q.size()); break; }
        }
    }
    cout << result;
}