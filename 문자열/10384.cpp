#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, len, val;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; i++) {
        string s; vector<int>v(26, 0);
        getline(cin, s);
        len = s.length();
        for (int i = 0; i < len; i++) if (isalpha(s[i]))v[tolower(s[i]) - 'a']++;
        val = *min_element(v.begin(), v.end()); s = "Case " + to_string(i) + ": ";
        if (val == 0)s += "Not a pangram\n";
        else if (val == 1)s += "Pangram!\n";
        else if (val == 2)s += "Double pangram!!\n";
        else s += "Triple pangram!!!\n";
        cout << s;
    }
}