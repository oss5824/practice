#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    deque<int>q;
    cin.ignore();
    while (n--) {
        string s; getline(cin, s);
        if (s[1] == 'u') {
            q.push_back(stoi(s.substr(5)));
        }
        else if (s[1] == 'o') {
            if (q.empty())cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        }
        else if (s[1] == 'i')cout << q.size() << "\n";
        else if (s[1] == 'm')cout << q.empty() << "\n";
        else if (s[1] == 'r')q.empty() ? cout << "-1\n" : cout << q.front() << "\n";
        else if (s[1] == 'a')q.empty() ? cout << "-1\n" : cout << q.back() << "\n";
    }
}