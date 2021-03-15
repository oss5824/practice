#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s1, s2;
bool check()
{
	int len = s1.length(), idx = 0;
	for (int i = 0; i < len; i++)
	{
		char c = s1[i]; int index = s2.find(c, idx);
		if (index != string::npos)idx = index + 1;
		else return false;
	}
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (cin >> s1) { cin >> s2; if (check())cout << "Yes\n"; else cout << "No\n"; }
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);