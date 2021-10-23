#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
int N, M, res = INF;
vector<int>v;
int solve(int len)
{
	int start = v[0], i = 0;
	int cnt = 0, sz = v.size(), result = 0;
	while (i < sz) {
		int val = start + len;
		while (i < sz - 1 && v[i + 1] <= val) {
			i++;
		}
		result = result + (v[i] - start);
		cnt++; 
		if (i == sz - 1)break;
		start = v[i + 1]; i++;
	}
	if (cnt == M) { res = min(res, result); }
	return cnt;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
	{ int a; cin >> a; v.push_back(a); }
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int s = 0, e = v.back() - v[0];
	while (s <= e) {
		int m = (s + e) / 2;
		if (solve(m) >= M)e--;
		else s++;
	}
	cout << res;
	return 0;
}

