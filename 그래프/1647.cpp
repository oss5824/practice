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
int N, M, par[100001];
vector<pair<int, pair<int, int>>>v;
int Find(int x) { if (x == par[x])return x; else return par[x] = Find(par[x]); }
bool Merge(int a, int b)
{
	a = Find(a); b = Find(b); if (a == b)return true;
	if (a > b)par[a] = b;
	else par[b] = a;
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)par[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	int sum=0, maxDist = 0;
	for (int i = 0; i < M; i++) {
		int dist = v[i].first;
		int a = v[i].second.first, b = v[i].second.second;
		if (!Merge(par[a], par[b]))
		{
			maxDist = max(dist, maxDist);
			sum += dist;
		}
	}
	cout << sum - maxDist;
	return 0;
}