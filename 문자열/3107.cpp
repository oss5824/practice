#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
string s;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> s;
    int len = s.length(), idx = 0;
    string tmp, result;
    if ((idx = s.find("::")) == string::npos) {
        for (int i = 0; i < len; i++) {
            if (s[i] == ':') { while (tmp.length() != 4)tmp = "0" + tmp; result += tmp + ":"; tmp = ""; }
            else tmp += s[i];
        }while (tmp.length() != 4)tmp = "0" + tmp; result += tmp;
    }
    else {
        int cnt = 0, cntF = 0;
        for (int i = 0; i < idx; i++) {
            if (s[i] == ':') { while (tmp.length() != 4)tmp = "0" + tmp; result += tmp + ":"; tmp = ""; cnt++; cntF++; }
            else tmp += s[i];
        }if (!tmp.empty()) { while (tmp.length() != 4)tmp = "0" + tmp; result += tmp + ":"; tmp = ""; cnt++; cntF++; }

        for (int i = idx + 2; i < len; i++) {
            if (s[i] == ':') { while (tmp.length() != 4)tmp = "0" + tmp; result += tmp + ":"; tmp = ""; cnt++; }
            else tmp += s[i];
        }if (!tmp.empty()) { while (tmp.length() != 4)tmp = "0" + tmp; result += tmp; tmp = ""; cnt++; }
        string zero = "0000:";
        while (cnt != 8) { result.insert(5*cntF, zero); cnt++; }
    }cout << result.substr(0, 39);

}