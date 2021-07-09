#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    while (1)
    {
        string s; int T = 0, N; vector<string>vs;
        while (1) {
            cin >> s;
            if (s == "QUIT" && T == 0)break;
            if (s == "NUM") { cin >> N; s += to_string(N); }
            vs.push_back(s); T++;
            if (s == "END")break;
        }
        if (s == "QUIT" && T == 0)break;
        cin >> T;
        for (int i = 0; i < T;i++) {
            cin >> N;
            bool check = true;
            stack<int>st; st.push(N);
            for (string str : vs) {
                string command = str.substr(0, 3);
                if (command == "NUM") {
                    int num = stoi(str.substr(3));
                    st.push(num);
                }
                else if (command == "POP") {
                    if (st.empty()) { check = false; break; }
                    st.pop();
                }
                else if (command == "INV") {
                    if (st.empty()) { check = false; break; }
                    int num = st.top(); st.pop(); st.push(-num);
                }
                else if (command == "DUP") {
                    if (st.empty()) { check = false; break; }
                    st.push(st.top());
                }
                else if (command == "SWP") {
                    if (st.size() < 2) { check = false; break; }
                    int a = st.top(); st.pop(); int b = st.top(); st.pop();
                    st.push(a); st.push(b);
                }
                else if (command == "ADD") {
                    if (st.size() < 2) { check = false; break; }
                    int a = st.top(); st.pop(); int b = st.top(); st.pop();
                    int c = b + a;
                    if (abs(c) > 1e9) { check = false; break; }
                    st.push(c);
                }
                else if (command == "SUB") {
                    if (st.size() < 2) { check = false; break; }
                    int a = st.top(); st.pop(); int b = st.top(); st.pop();
                    int c = b - a;
                    if (abs(c) > 1e9) { check = false; break; }
                    st.push(c);
                }
                else if (command == "MUL") {
                    if (st.size() < 2) { check = false; break; }
                    long long a = (long long)st.top(); st.pop(); 
                    long long b = (long long)st.top(); st.pop();
                    long long c = b * a;
                    if (abs(c) > 1e9) { check = false; break; }
                    st.push((int)c);
                }
                else if (command == "DIV") {
                    if (st.size() < 2) { check = false; break; }
                    int a = st.top(); st.pop(); int b = st.top(); st.pop();
                    if (a == 0) { check = false; break; }
                    int cnt = 0;
                    if (a < 0) { a = abs(a); cnt++; }if (b < 0) { b = abs(b); cnt++; }
                    int c = b / a;
                    if (cnt == 1)c *= -1;
                    if (abs(c) > 1e9) { check = false; break; }
                    st.push(c);
                }
                else if (command == "MOD") {
                    if (st.size() < 2) { check = false; break; }
                    int a = st.top(); st.pop(); int b = st.top(); st.pop();
                    if (a == 0) { check = false; break; }
                    int c = (abs(b)) % (abs(a));
                    if (b < 0)c *= -1;
                    if (abs(c) > 1e9) { check = false; break; }
                    st.push(c);
                }
                else break;
            }
            if (!check || st.size() != 1)cout << "ERROR\n";
            else cout << st.top() << "\n";
        }
        cout << "\n";
    }
}