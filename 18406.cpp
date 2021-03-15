#include <iostream>
#include <string>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s; cin >> s; int len = s.length(), lsum = 0, rsum = 0, idx = 0;
	while (idx < len / 2) { int c = s[idx++] - '0'; lsum += c; }
	while (idx < len) { int c = s[idx++] - '0'; rsum += c; }
	(lsum == rsum) ? cout << "LUCKY" : cout << "READY";
	return 0;
}
