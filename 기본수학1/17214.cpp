#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
int N;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    string s; cin >> s;
    if (s == "0") { cout << "W"; return 0; }
    int len = s.length();
    string result;
    string num;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'x')
        {
            int val = stoi(num) / 2; num = "";
            if (abs(val) == 1) {
                if (val == 1)result += "+xx";
                else result += "-xx";
            }
            else result += to_string(val) + "xx";
        }
        else num += s[i];
    }
    if (!num.empty()) {
        int val = stoi(num);
        if (abs(val) == 1) {
            if (val == 1)result += "+x+W";
            else result += "-x+W";
        }
        else result += num + "x+W";
    }
    else result += "+W";
    if (result[0] == '+')result.erase(0, 1);
    cout << result << "\n";
}