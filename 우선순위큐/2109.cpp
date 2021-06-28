#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
bool cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.second == b.second)return a.first > b.first;
    else return a.second < b.second;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    int max_value = 0;
    vector<pair<int, int>>v;//µ·, ±â°£
    priority_queue<int, vector<int>, greater<int>>q;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b; v.push_back({ a,b }); max_value = max(max_value, b);
    }
    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int time = v[i].second, cost = v[i].first;
        if (q.size() < time)q.push(cost);
        else if (q.size() == time && q.top() < cost) { q.pop(); q.push(cost); }
    }
    while (!q.empty()) { sum += q.top(); q.pop(); }
    cout << sum;
}




/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long a : numbers) {
        for (long long val = a + 1;; val++) {
            long long result = val ^ a;
            int cnt = 0;
            while (result) { if (result & 1)cnt++; result = result >> 1; }
            if (cnt <= 2) { answer.push_back(val); break; }
        }
    }
    return answer;
}
int main()
{
    vector<long long>v = solution({ 2,7 });
    for (long long p : v)cout << p << " ";
}
*/