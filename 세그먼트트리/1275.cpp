#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<limits.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll N,Q, arr[100000], t[400000];
ll init(int s, int e, int n)
{
	if (s == e)return t[n] = arr[s];
	int m= (s + e) / 2;
	return t[n] = init(s, m, 2 * n) + init(m + 1, e, 2 * n + 1);
}
ll sum(int s, int e,int l,int r, int n)
{
	if (s > r || e < l)return 0;
	if (l <= s && e <= r)return t[n];
	int m = (s + e) / 2;
	return sum(s, m, l, r, 2 * n) + sum(m + 1, e, l, r, 2 * n + 1);
}
void update(int s, int e, int idx, ll diff, int n)
{
	if (!(s <= idx && idx <= e))return;
	t[n] = t[n] - diff;
	if (s != e)
	{
		int m = (s + e) / 2;
		update(s, m, idx, diff, 2 * n); update(m + 1, e, idx, diff, 2 * n + 1);
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 0; i < N; i++)cin >> arr[i];
	init(0, N - 1, 1);
	while (Q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)swap(x, y);
		cout << sum(0, N - 1, x - 1, y - 1, 1) << "\n";
		ll diff = arr[a - 1] - b;
		update(0, N - 1, a - 1, diff, 1);
		arr[a - 1] = b;
	}
	return 0;
}


