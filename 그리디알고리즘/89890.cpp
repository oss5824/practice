#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K, res, arr[2001];
vector<pair<pair<int, int>,int>>v;
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	while (K--) { int a, b, c; scanf("%d %d %d", &a, &b, &c); v.push_back({ { a,b }, c }); }
	sort(v.begin(), v.end(), [](pair<pair<int, int>, int>a, pair<pair<int, int>, int>b)->bool {
		if (a.first.second == b.first.second) return a.first.first < b.first.first;
		return a.first.second < b.first.second;
	});
	for (pair<pair<int, int>, int>p : v) {
		int l = p.first.first, r = p.first.second, n = p.second, val = *max_element(arr + l, arr + r);
		val = min(M - val, n); res += val; for (int i = l; i < r; i++)arr[i] += val;
	}printf("%d", res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


