#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
int N, par[300001], a, b;
int find(int n) { if (n == par[n])return n; else return par[n] = find(par[n]); }
void merge(int a, int b)
{
	a = find(a), b = find(b); if (a == b)return;
	par[a] = b;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 1; i <= N; i++)par[i] = i;
	for (int i = 1; i <= N - 2; i++) { cin >> a >> b; merge(a, b); }
	for (int i = 1; i <= N; i++) { if (find(par[i]) == i)cout << i << " "; }
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);