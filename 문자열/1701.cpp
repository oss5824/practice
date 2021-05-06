#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
string s1;
int result;
void search(string s2)
{
	int len2 = s2.length(), cnt = 0;
	vector<int>pi(len2, 0);
	for (int i = 1, j = 0; i < len2; i++) {
		while (j != 0 && s2[i] != s2[j])j = pi[j - 1];
		if (s2[i] == s2[j]) { pi[i] = ++j; result = max(result, j); }
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s1; 
	int len = s1.length();
	string s2;
	for (int i = 0; i < len; i++)
	{
		s2 = s1.substr(i, len - i);
		search(s2);
	}
	cout << result;
	return 0;
}