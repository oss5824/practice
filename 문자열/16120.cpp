#include <string>
#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    string s; cin >> s;
    string st;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') {
            if (!st.empty()) {
                if (st.back() == 'P')st.push_back('P');
                else if (st.back() == 'A') { st.pop_back(); st.pop_back(); st.pop_back(); st.push_back('P'); }
            }
            else st.push_back('P');
        }
        else {
            if (st.empty()) { cout << "NP"; return 0; }
            else if (st.back() == 'A') { cout << "NP"; return 0; }
            else if (st.size() == 1) { cout << "NP"; return 0; }
            else st.push_back('A');
        }
    }
    if (st == "P")cout << "PPAP"; else cout << "NP";
}