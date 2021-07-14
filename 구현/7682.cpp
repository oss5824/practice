#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
string s;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    while (1) {
        cin >> s; if (s == "end")break;
        string valid = "valid\n", invalid = "invalid\n";
        int cntX = 0, cntO = 0;
        for (int i = 0; i < 9; i++)if (s[i] == 'X')cntX++; else if (s[i] == 'O')cntO++;
        if (cntX < cntO || cntX>cntO + 1) { cout << invalid; continue; }
        bool canX = false, canO = false;
        for (int i = 0; i < 9; i += 3) {
            if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
                if (s[i] == 'X')canX = true; else if (s[i] == 'O')canO = true;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (s[i] == s[i + 3] && s[i + 3] == s[i + 6]) {
                if (s[i] == 'X')canX = true; else if (s[i] == 'O')canO = true;
            }
        }
        if (s[0] == s[4] && s[4] == s[8]) { if (s[0] == 'X')canX = true; else if (s[0] == 'O')canO = true; }
        if (s[2] == s[4] && s[4] == s[6]) { if (s[2] == 'X')canX = true; else if (s[2] == 'O')canO = true; }
        if (canX && canO)cout << invalid;
        else if (canO && (cntX > cntO))cout << invalid;
        else if (canX && (cntX <= cntO))cout << invalid;
        else if ((!canO && !canX) && (cntX + cntO) != 9)cout << invalid;
        else cout << valid;
    }
}