#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<regex>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N; string s; cin >> N;
	while (N--) {
		cin >> s;
		regex reg("(100+1+|01)+");
		if (regex_match(s, reg))cout << "YES\n";
		else cout << "NO\n";
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);