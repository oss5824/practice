#include<iostream>
#include<string>
typedef long long ll;
using namespace std;
string s;
int len;
bool can(char c) { if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')return true; else return false; }
ll solve(int pos,int aeiou,int remain,  bool l)
{
	if (aeiou == 3 || remain == 3)return 0;
	if (pos == len) { if (l)return 1; else return 0; }
	ll sum = 0;
	if (s[pos] == '_') {
		sum+=solve(pos + 1, 0, remain + 1, true);
		sum += 5 * solve(pos + 1, aeiou + 1, 0, l);
		sum += 20 * solve(pos + 1, 0, remain + 1, l);
	}
	else {
		char c = s[pos];
		if (c == 'L')l = true;
		if (can(c))sum+=solve(pos + 1, aeiou + 1, 0, l);
		else sum+=solve(pos + 1, 0, remain + 1, l);
	}
	return sum;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s; len = s.length();
	cout<<solve(0,0,0, false);
	return 0;
}