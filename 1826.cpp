#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, a, b, e, remain, result;
vector<pair<int, int>>v;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> a >> b; v.push_back({ a,b }); }
    cin >> e >> remain;
    sort(v.begin(), v.end());
    priority_queue<int>q;
  
    int pos = remain;
    for (int i = 0; i < N; i++)
    {
        int location = v[i].first, charge = v[i].second;
        if (location <= pos) { q.push(charge); }
        else {
            while (!q.empty() && location > pos) {
                int value = q.top(); q.pop(); result++;
                pos += value;
            }
            if (location > pos) { cout << "-1"; return 0; }
            q.push(charge);
        }
    }
    while (!q.empty() && e > pos) {
        int value = q.top(); q.pop(); result++;
        pos += value;
    }
    if (e > pos) cout << "-1";
    else cout << result;
}