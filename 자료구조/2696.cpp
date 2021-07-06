#include <iostream>
#include <queue>
using namespace std;
int T, N;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        int a, cnt = 0; cin >> a;
        priority_queue<int>left; priority_queue<int, vector<int>, greater<int>>right;
        queue<int>q; q.push(a); right.push(a);
        if (N >= 2) {
            cin >> a; 
            if (a > right.top()) left.push(right.top()), right.pop(), right.push(a); else left.push(a);
        }
        for (int i = 3; i <= N; i++){
            cin >> a;
            if (left.size() < right.size()) {
                if (right.top() < a) { left.push(right.top()); right.pop(); right.push(a); }
                else left.push(a);
            }
            else {
                if (left.top() > a) { right.push(left.top()); left.pop(); left.push(a); }
                else right.push(a);
            }
            if (i % 2 == 1)q.push(right.top());
        }
        cout << q.size() << "\n";
        while (!q.empty()) { cnt++; cout << q.front() << " "; q.pop(); if (cnt % 10 == 0)cout << "\n"; }
        if (cnt % 10 != 0)cout << "\n";
    }
}