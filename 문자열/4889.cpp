#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int num = 1;
    while (1) {
        string s; cin >> s;
        if (s[0] == '-')break;
        string st;
        int len = s.length(), cnt = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '{') st.push_back('{');
            else {
                if (s[i] == '}'){
                    if (st.empty() || st.back() == '}')st.push_back('}');
                    else st.pop_back();
                }
            }
        }
        len = st.size();
        for (int i = 0; i < len; i += 2) {
            if (st[i] == '}')cnt++;
            if (st[i + 1] == '{')cnt++;
        }
        cout << num++ << ". " << cnt << "\n";
    }
}