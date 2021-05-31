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
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
int N, M;
map<string, int>m;
bool cmp(pair<string, int>a, pair<string, int>b)
{
	return a.second < b.second;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		m[s] = cnt++;
	}
	vector<pair<string, int>>v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	int i = 0;
	for (pair<string, int>p : v)
	{
		i++;
		cout << p.first << "\n";
		if (i == N)break;
	}
	return 0;
}

