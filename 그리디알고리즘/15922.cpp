#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int N;
pair<int, int>v[100000];
bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first)return a.second > b.second;
	return a.first < b.first;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> v[i].first >> v[i].second;
	sort(v, v + N, cmp);
	int e = -2e9, len = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].second < e)continue;
		if (e < v[i].first) e = v[i].second, len += e - v[i].first;
		else len += v[i].second - e, e = v[i].second;
	}cout << len;
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);