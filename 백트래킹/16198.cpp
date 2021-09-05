#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int N, s;
vector<int>v;
void solve(int c)
{
	if (v.size() == 2) { if (s < c)s = c; return; }
	int len = v.size();
	for (int i = 1; i < len - 1; i++) {
		int val = v[i], n = v[i - 1] * v[i + 1]; v.erase(v.begin() + i);
		solve(c + n);
		v.insert(v.begin() + i, val);
	}
}
int main()
{
	scanf("%d", &N); for (int i = 0, a; i < N; i++) { scanf("%d", &a); v.push_back(a); }
	solve(0); printf("%d", s);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);


