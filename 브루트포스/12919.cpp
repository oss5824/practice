#include <iostream>
#include<algorithm>
using namespace std;
string s,t;
bool chk = false;
void solve()
{
	if (chk)return;
	if (s.length() == t.length()) { if (s == t)chk = true; return; }
	if (t.back() == 'A') { t.pop_back(); solve(); t.push_back('A'); }
	if (t.front() == 'B') {
		reverse(t.begin(), t.end()); t.pop_back(); solve(); 
		t.push_back('B'); reverse(t.begin(), t.end());
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> s >> t;
	solve(); cout << chk;
}
