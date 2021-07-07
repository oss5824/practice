#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N, a, arr[1000001];
vector<int>tmp, v;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> a; tmp.push_back(a); arr[a]++; }
    for (int i = 0; i < N; i++) { v.push_back(arr[tmp[i]]); }
    stack<pair<int, int>>s; stack<int>st;
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && v[i] >= s.top().first) { s.pop(); }
        if (s.empty())st.push(-1); else st.push(tmp[s.top().second]);
        s.push({ v[i],i });
    }
    while (!st.empty())cout << st.top() << " ", st.pop();
}