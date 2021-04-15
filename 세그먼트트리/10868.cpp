#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 1000000001
using namespace std;
int N, M;
int arr[100001], tree[400004];
int init(int s, int e, int n)
{
	if (s == e)return tree[n] = arr[s];
	int m = (s + e) / 2;
	return tree[n] = min(init(s, m, 2 * n), init(m + 1, e, 2 * n + 1));
}
int min_tree(int s, int e, int l, int r, int n)
{
	if (s > r || e < l)return INF;
	if (l <= s && e <= r)return tree[n];
	int m = (s + e) / 2;
	return min(min_tree(s, m, l, r, 2 * n), min_tree(m + 1, e, l, r, 2 * n + 1));
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> arr[i];
	init(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		cout << min_tree(0, N - 1, a - 1, b - 1, 1) << "\n";
	}
	return 0;
}

