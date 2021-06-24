#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

string s;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> s;
	int idx = 0, len = s.length(), remainlen = len;
	if (len == 1) { cout << "NO"; return 0; }
	while (idx < len)
	{
		if (remainlen == 1) { cout << "NO"; break; }
		else if (remainlen == 2) {
			if (s[idx] == 'p' && s[idx + 1] == 'i') {
				cout << "YES"; break;
			}
			else if (s[idx] == 'k' && s[idx + 1] == 'a') {
				cout << "YES"; break;
			}
			else { cout << "NO"; break; }
		}
		else if (remainlen == 3) {
			if (s[idx] == 'c' && s[idx + 1] == 'h' && s[idx + 2] == 'u') {
				cout << "YES"; break;
			}
			else { cout << "NO"; break; }
		}
		else {
			if (s[idx] == 'p' && s[idx + 1] == 'i') { idx += 2; remainlen -= 2; }
			else if (s[idx] == 'k' && s[idx + 1] == 'a') { idx += 2; remainlen -= 2; }
			else if (s[idx] == 'c' && s[idx + 1] == 'h' && s[idx + 2] == 'u') {
				idx += 3; remainlen -= 3;
			}
			else { cout << "NO"; break; }
		}
	}
	return 0;
}
