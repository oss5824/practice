#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int N;
vector<pair<string, int>>v;
vector<pair<string, int>>root;
bool cmp(pair<string, int>a, pair<string, int>b) { if (a.first == b.first)return a.second < b.second; else return a.first < b.first; }
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < 5 * N; i++) {
        string s; cin >> s; root.push_back({ s.substr(0,1),stoi(s.substr(2)) });
    }
    v = root;
    sort(v.begin(), v.end(), cmp);
    stack<pair<string, int>>st;
    int i = 0, j = 0;
    for (; j < 5 * N && i < 5 * N;) {
        if (root[i].first == v[j].first && root[i].second == v[j].second)i++, j++;
        else if (!st.empty() && st.top().first == v[j].first && st.top().second == v[j].second)st.pop(), j++;
        else st.push(root[i++]);
    }
    while (!st.empty()) { if (!(st.top().first == v[j].first && st.top().second == v[j].second)) { cout << "BAD"; return 0; }st.pop(); j++; }
    cout << "GOOD";
}