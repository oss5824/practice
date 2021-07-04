#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    map<string, int>match; string s, str; int N, M;
    cin >> N;
    while (N--) {
        cin >> s; if (s.length() > 2) { sort(s.begin() + 1, s.end() - 1); }match[s]++;
    }
    cin >> M;
    cin.ignore();
    while (M--) {
        getline(cin, s); int cnt = 1;
        istringstream iss(s);;
        while (getline(iss, str, ' ')) {
            if (str.length() > 2) { sort(str.begin() + 1, str.end() - 1); }cnt *= match[str];
        }
        printf("%d\n", cnt);
    }
}