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
#define INF ll_MAX
typedef long long ll;
using namespace std;
int N, M;
map<string, vector<string>>m;
map<string, string>p;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s; int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string s1; cin >> s1; p[s1] = s;
			m[s].push_back(s1);
		}
	}
	for (int i = 0; i < M; i++) {
		string s; cin >> s; int n; cin >> n;
		if (n == 0) {
			vector<string>v = m[s];
			sort(v.begin(), v.end());
			for (string str : v)cout << str << "\n";
		}
		else cout << p[s] << "\n";
	}
	
	return 0;
}
