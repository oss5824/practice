#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int n = 1;
    while (1) {
        int a, b; bool fin = false;
        map<int, int>m; int cnt = 0;
        set<int>st;
        while (1) {
            cin >> a >> b;
            if (a == 0 && b == 0)break;
            if (a < 0 && b < 0) { fin = true; break; }
            m[b]++; cnt++; st.insert(a); 
        }
        if (fin)break;
        else {
            bool exist = false, can = false;
            for (pair<int,int>p : m) {
                if (p.second != 1) { can = true; break; }
            }
            for (int i : st) {
                if (m[i] == 0) {
                    if (exist == true) { can = true; break; }
                    exist = true;
                }
            }
            string s = "";
            if ((can || !exist)&&st.size()!=0)s = "not ";
            cout << "Case " << n << " is " << s << "a tree.\n";
        }
        n++;
    }
}