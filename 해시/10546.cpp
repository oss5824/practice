#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#include<string>
#include<queue>
#define INF 1e9
typedef unsigned long long ull;
using namespace std;
map<string, int>m;
int N;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) { string s; cin >> s; m[s]++; }
	string s;
	while (cin >> s) {
		m[s]--;
	}
	vector<pair<string, int>>v(m.begin(), m.end());
	for (pair<string, int>p : v) {
		int len = p.second;
		if (len > 0) { cout << p.first; break; }
	}
	return 0;
}
