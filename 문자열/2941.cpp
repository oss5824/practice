#include<iostream>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int pos;
	string s; cin >> s; string f[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	for (string c : f)
		if (s.find(c) != string::npos)
		{
			while ((pos = s.find(c)) != string::npos) { s.erase(pos, c.length()); s.insert(pos, "*"); }
		}
	cout << s.length();
	return 0;
}