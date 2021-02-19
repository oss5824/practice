#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll arr[100001], t[400004], lazy[400004], result = 0;
ll make_tree(int s, int e, int n)
{
	if (s == e)return t[n] = arr[s];
	int m = (s + e) / 2;
	return t[n] = make_tree(s, m, 2 * n) + make_tree(m + 1, e, 2 * n + 1);
}
void propagate(int s, int e, int n)
{
	if (lazy[n] != 0)
	{
		t[n] += ((ll)(e - s + 1)) * lazy[n];
		if (s != e) { lazy[2 * n] += lazy[n]; lazy[2 * n + 1] += lazy[n]; }
		lazy[n] = 0;
	}
}
void sum(int s, int e, int l, int r, int n, ll d)
{
	propagate(s, e, n);
	if (l > e || r < s)return;
	if (l <= s && e <= r)
	{
		t[n] += ((ll)(e - s + 1)) * d;
		if (s != e) { lazy[2 * n] += d; lazy[2 * n + 1] += d; }
		return;
	}
	int m = (s + e) / 2; sum(s, m, l, r, 2 * n, d); sum(m + 1, e, l, r, 2 * n + 1, d);
	t[n] = t[2 * n] + t[2 * n + 1];
}
void search(int s, int e, int i, int n)
{
	propagate(s, e, n);
	if (i<s || i>e)return;
	if (s != e) { int m = (s + e) / 2; search(s, m, i, 2 * n); search(m + 1, e, i, 2 * n + 1); }
	else { result = t[n]; return; }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, c; ll d; cin >> n; for (int i = 0; i < n; i++)cin >> arr[i];
	cin >> m; make_tree(0, n - 1, 1);
	while (m--)
	{
		cin >> a;
		if (a == 1) { cin >> b >> c >> d; sum(0, n - 1, b - 1, c - 1, 1, d); }
		else { cin >> b; search(0, n - 1, b - 1, 1); cout << result << "\n"; }
	}
	return 0;
}
