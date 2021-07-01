#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int N, a, b;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    priority_queue<int, vector<int>, greater<int>>q; vector<pair<int, int>>v;
    for (int i = 0; i < N; i++) { cin >> a >> b; v.push_back({ a,b }); }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        if (q.empty() || q.top() > v[i].first)q.push(v[i].second);
        else { q.pop(); q.push(v[i].second); }
    }
    cout << q.size();
}