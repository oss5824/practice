#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;
map<string, vector<string>>match;
set<string>member;
int getNum(string& s)
{
    if (member.count(s) == 1)return 0;
    member.insert(s);
    if (match[s].size() == 0)return 1;
    int cnt = 0;
    for (string& str : match[s]) { if (member.count(str) == 0) { cnt += getNum(str); } }
    return cnt;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N;
    while (1) {
        cin >> N; if (N == 0)break;
        bool check = false; vector<string>vs; match.clear(); member.clear();
        while (N--) {
            string s, str, top; cin >> s;
            istringstream iss(s); getline(iss, top, ':');
            while (getline(iss, str, ',')) {
                if (str.back() == '.')str.pop_back(); match[top].push_back(str);
                if (!check)vs.push_back(str);
            }
            check = true;
        }
        int sum = 0;
        for (string& val : vs) sum += getNum(val);
        cout << sum << "\n";
    }
}