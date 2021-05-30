#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
int N;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		string s; cin >> s;
		int len = s.length();
		if (len % 2 == 0){
			string s1 = s.substr(0, len / 2), s2 = s.substr(len / 2, len / 2);
			reverse(s2.begin(), s2.end());
			if (s1 == s2) { cout << "0\n"; continue; }
		}
		else if (len % 2 == 1) {
			string s1 = s.substr(0, len / 2 + 1), s2 = s.substr(len / 2, len / 2 + 1);
			reverse(s2.begin(), s2.end());
			if (s1 == s2) { cout << "0\n"; continue; }
		}
		int l = 0, r = len - 1, cnt = 0;
		bool check = false;
		while (l <= r)
		{
			if (s[l] == s[r]) { l++; r--; }
			else if (cnt != 0) { cnt++; break; }
			else { cnt++; l++; if (l >= r) { check = true; break; } }
		}
		if (check || cnt <= 1) { cout << "1\n"; continue; }
		l = 0, r = len - 1; cnt = 0;
		while (l <= r)
		{
			if (s[l] == s[r]) { l++; r--; }
			else if (cnt != 0) { cnt++; break; }
			else { cnt++; r--; if (l >= r) { check = true; break; } }
		}
		if (cnt <= 1 || check)cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}