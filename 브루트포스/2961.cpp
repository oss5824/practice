#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int N, res = 1e9;
bool visit[10];
pair<int, int>arr[10];
vector<int>v;
void solve(int n)
{
	int a = 1, b = 0;
	for (int i : v) { a *= arr[i].first; b += arr[i].second; }
	if (v.size() != 0)res = min(res, abs(a - b));
	if (n == N)return;
	for (int i = n; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			solve(i + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> arr[i].first >> arr[i].second;
	solve(0); cout << res;
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);