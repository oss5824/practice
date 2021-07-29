#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<algorithm>
using namespace std;
int N, M, O, P, Q, cnt, arr[100001], par[100001];
int Find(int n) { if (n == par[n])return n; else return par[n] = Find(par[n]); }
void merge(int q,int a, int b)
{
	a = Find(a), b = Find(b); if (a == b)return;
	if (arr[a] < arr[b])swap(a, b);
	par[b] = a; if (q == 1)arr[a] += arr[b]; else arr[a] -= arr[b];
	arr[b] = 0;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; for (int i = 1; i <= N; i++)par[i] = i, cin >> arr[i];
	while (M--) { cin >> O >> P >> Q;; merge(O, par[P], par[Q]); }
	sort(arr + 1, arr + N + 1); for (int i = 1; i <= N; i++)if (arr[i] != 0)cnt++;
	cout << cnt << "\n";for (int i = 1; i <= N; i++) if (arr[i] != 0)cout << arr[i] << " ";
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);