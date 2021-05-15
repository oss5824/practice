#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N;
map<string, int>m;
bool cmp(pair<string, int>a, pair<string, int>b)
{
	if (a.second > b.second)return true;
	else if (a.second < b.second)return false;
	else return a.first < b.first;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) { string s; cin >> s; m[s]++; }
	vector<pair<string, int>>v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first;
	return 0;
}