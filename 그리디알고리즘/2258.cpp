#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, s, b = -1, c, r = 2147483647;
bool f;
pair<int, int>v[100000];
bool cmp(pair<int, int>a, pair<int, int>b) { if (a.first != b.first)return a.first < b.first; return a.second > b.second; }
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false); cin >> N >> M;
	for (int i = 0, x, y; i < N; i++)cin >> x >> y, v[i].second = x, v[i].first = y;
	sort(v, v + N, cmp);
	for (int i = 0; i < N; i++) { if (b != v[i].first)c = 0; c++; b = v[i].first; s += v[i].second; if (s >= M) { r = min(r, c * v[i].first); f = true; } }
	f ? printf("%d", r) : printf("-1");
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


