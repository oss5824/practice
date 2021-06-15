#pragma warning(disable: 4996)
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
using namespace std;
int T;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		int N; cin >> N;
		map<string, int>m;
		int mapping[1001];
		for (int i = 1; i <= N; i++) {
			string s; cin >> s; m[s] = i;
		}
		for (int i = 1; i <= N; i++) {
			string s; cin >> s; mapping[m[s]] = i;
		}
		string str[1001];
		for (int i = 1; i <= N; i++) cin >> str[i];

		for (int i = 1; i <= N; i++)cout << str[mapping[i]] << " ";
		cout << "\n";
	}
	return 0;
}