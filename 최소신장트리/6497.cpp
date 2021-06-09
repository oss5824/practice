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
typedef long long ll;
using namespace std;
int par[200000];
int N, M;
vector<pair<int, pair<int, int>>>v;
int Find(int x) { if (x == par[x])return x; else return par[x] = Find(par[x]); }
bool Merge(int x, int y)
{
	x = Find(x); y = Find(y); if (x == y)return false;
	if (x > y)par[x] = y;
	else par[y] = x;
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		int sum = 0; v.clear();
		for (int i = 0; i < M; i++) {
			int a, b, c; cin >> a >> b >> c; sum += c;
			v.push_back({ c,{a,b} });
		}
		for (int i = 0; i < N; i++)par[i] = i;
		int dist = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < M; i++) {
			int val = v[i].first, a = v[i].second.first, b = v[i].second.second;
			if (!Merge(par[a], par[b]))continue;
			dist += val;
		}
		cout << sum - dist << "\n";
	}


	return 0;
}


