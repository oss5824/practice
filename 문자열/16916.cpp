#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
string s1, s2;
void search()
{
	int len1 = s1.length(), len2 = s2.length();
	vector<int>pi(len2, 0);
	for (int i = 1, j = 0; i < len2; i++) {
		while (j != 0 && s2[i] != s2[j])j = pi[j - 1];
		if (s2[i] == s2[j])pi[i] = ++j;
	}
	for (int i = 0, j = 0; i < len1; i++) {
		while (j != 0 && s1[i] != s2[j])j = pi[j - 1];
		if (s1[i] == s2[j] && j == len2 - 1) { cout << "1"; return; }
		else if (s1[i] == s2[j])j++;
	}
	cout << "0";
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s1 >> s2; search();
	return 0;
}