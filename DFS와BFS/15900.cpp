#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int N;
long long r;
vector<int>v[500001];
void dfs(int s, int b, long long d)
{
	bool c = false;
	for (int n : v[s]) { if (b == n)continue; c = true; dfs(n, s, d + 1); }
	if (!c)r += d;
}
int main()
{
	cin.tie(NULL);ios::sync_with_stdio(false);
	cin >> N; for (int i = 0, a, b; i < N - 1; i++) { cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	dfs(1, 0, 0); r % 2 ? printf("Yes") : printf("No");
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


