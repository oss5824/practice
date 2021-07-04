#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
deque<ll>num;
deque<char>oper;
ll result(ll a, ll b, char oper)
{
    if (oper == '+')return a + b;
    else if (oper == '-')return a - b;
    else if (oper == '*')return a * b;
    else return a / b;
}
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    string s, tmp; cin >> s;
    int idx = 0, len = s.length();
    if (s[0] == '-') { idx = 1; tmp = '-'; while (idx < len && isdigit(s[idx]))tmp += s[idx++]; }
    else { while (idx < len && isdigit(s[idx]))tmp += s[idx++]; }
    if (idx == len) { cout << stoll(tmp); return 0; }
    num.push_back(stoll(tmp)); oper.push_back(s[idx++]);
    tmp = "";
    for (; idx < len; idx++){
        if (isdigit(s[idx])) tmp += s[idx];   
        else {
            num.push_back(stoll(tmp));
            oper.push_back(s[idx]);
            tmp = "";
        }
    }
    num.push_back(stoll(tmp));
    map<char, int>m; m['+'] = 1; m['-'] = 1; m['*'] = 2; m['/'] = 2;
    while (!oper.empty()) {
        int numLen = num.size()-1;
        int operLen = oper.size() - 1;
        char firstOper = oper[0], lastOper = oper[operLen];
        if (m[firstOper] == m[lastOper])
        {
            long long res1 = result(num[0], num[1], firstOper);
            long long res2 = result(num[operLen], num[operLen + 1], lastOper);
            if (res1 >= res2) { num.pop_front(); num.pop_front(); num.push_front(res1); oper.pop_front(); }
            else { num.pop_back(); num.pop_back(); num.push_back(res2); oper.pop_back(); }
        }
        else if(m[firstOper] < m[lastOper]){
            long long res2 = result(num[operLen], num[operLen + 1], lastOper);
            num.pop_back(); num.pop_back(); num.push_back(res2); oper.pop_back();
        }
        else {
            long long res1 = result(num[0], num[1], firstOper);
            num.pop_front(); num.pop_front(); num.push_front(res1); oper.pop_front();
        }
    }
    cout << num[0];
}