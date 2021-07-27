#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.second == b.second)return a.first > b.first;
	else return a.second < b.second;
}
int main()
{
	cin.tie(NULL);ios::sync_with_stdio(false);
	int C, N, a, b, cnt = 0; cin >> C >> N; priority_queue<int, vector<int>, greater<int>>q; for (int i = 0; i < C; i++) { cin >> a; q.push(a); }
	vector<pair<int, int>>v;
	for (int i = 0; i < N; i++) { cin >> a >> b; v.push_back({ a,b }); }sort(v.begin(), v.end(), cmp);
	while (!q.empty()) {
		int t = q.top(), len = v.size();
		for (int i = 0; i < len; i++) {
			if (v[i].first <= t && t <= v[i].second) { cnt++; v.erase(v.begin() + i); break; }
		}q.pop();
	}cout << cnt;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);