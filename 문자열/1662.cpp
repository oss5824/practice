#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
string s;
int len, arr[51];
int solution(int idx)
{
    int cnt = 0;
    for (int i = idx; i < len; i++) {
        if (i == len - 1) {
            if (s[i] == ')')return cnt;
            else cnt++;
        }
        else {
            if (s[i] == ')')return cnt;
            else if (s[i + 1] == '(') { return cnt + (s[i] - '0') * solution(i + 2) + solution(arr[i + 1] + 1); }
            else cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> s; len = s.length();
    stack<int>st;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i]))continue;
        if (s[i] == '(')st.push(i);
        else { arr[st.top()] = i; st.pop(); }
    }
    cout << solution(0);
}