#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int T, N;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        map<int, int>m;
        while (N--) {
            char c; int v; cin >> c >> v;
            if (c == 'I')m[v]++;
            else 
            {
                if (!m.empty()) {
                    if (v == 1) {
                        (*m.rbegin()).second--;
                        if ((*m.rbegin()).second == 0)m.erase((*m.rbegin()).first);
                    }
                    else {
                        (*m.begin()).second--;
                        if ((*m.begin()).second == 0)m.erase((*m.begin()).first);
                    }
                }
            }
        }
        if (m.empty())cout << "EMPTY\n";
        else cout << (*m.rbegin()).first << " " << (*m.begin()).first << "\n";
        
    }
}