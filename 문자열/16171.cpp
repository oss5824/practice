#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s, s1, s2; cin >> s1 >> s2; for (int i = 0; i < s1.length(); i++)if (isalpha(s1[i]))s += s1[i];
	if (s.find(s2) != string::npos)cout << "1"; else cout << "0";
}