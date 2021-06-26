#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    string s, p, str; cin >> s >> p;
    int lenS = s.length();
    for (int i = 0; i < lenS; i++)if (isalpha(s[i]))str += s[i];
    if (str.find(p) != string::npos)cout << "1"; else cout << "0";
    return 0;
}