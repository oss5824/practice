#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s; getline(cin, s);
	string tmp; getline(cin, tmp);
	int idx = 0, len = s.length(), tmp_len = tmp.length();
	int cnt = 0;
	while (idx < len) {
		string sub = s.substr(idx, tmp_len);
		if (sub == tmp) { idx += tmp_len; cnt++; }
		else idx++;
	}cout << cnt;
	return 0;
}


