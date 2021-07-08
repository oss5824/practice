#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int len;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    while (1)
    {
        string s; cin >> s;
        if (s == "*")break;
        len = s.length();
        bool check = true;
        for (int i = 1; i < len; i++) {
            set<string>st;
            for (int j = 0; j < len - i; j++) {
                string tmp; tmp.push_back(s[j]); tmp.push_back(s[j + i]);
                if (st.count(tmp)) { check = false; break; }
                st.insert(tmp);
            }
            if (!check)break;
        }
        if (check)cout << s << " is surprising.\n";
        else cout << s << " is NOT surprising.\n";
    }
}