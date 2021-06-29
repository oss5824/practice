#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<string, int>>vs;
int N, K;
bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.first.length() == b.first.length())return a.second < b.second;
    else return a.first.length() < b.first.length();
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> K; for (int i = 1; i <= N; i++) { string s; cin >> s; vs.push_back({ s,i }); }
    sort(vs.begin(), vs.end(), cmp);
    queue<int>q;
    int beforeLen = 0;
    long long sum = 0;
    for (pair<string, int>p : vs) {
        int len = p.first.length(), record = p.second;
        if (beforeLen == len) {
            while (!q.empty() && abs(q.front() - record) > K) {
                q.pop();
            }
            if (q.empty()) { q.push(record); }
            else { sum += (long long)q.size(); q.push(record); }
        }
        else {
            beforeLen = len; while (!q.empty())q.pop();
            q.push(record);
        }
    }
    cout << sum;
}