#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
typedef long long ll;
using namespace std;
ll N, M;
ll arr[1000001], t[4000001];
ll Sum(ll s, ll e, ll l, ll r, ll n)
{
	if (l > e || s > r)return 0;
	if (l <= s && e <= r)return t[n];
	ll m = (s + e) / 2;
	return Sum(s, m, l, r, 2 * n) + Sum(m + 1, e, l, r, 2 * n + 1);
}
void Update(ll s, ll e,ll idx, ll n, ll diff)
{
	if (!(s <= idx && idx <= e))return;
	t[n] += diff;
	if (s != e)
	{
		ll m = (s + e) / 2;
		Update(s, m, idx, 2 * n, diff); Update(m + 1, e, idx, 2 * n + 1, diff);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	while (M--)
	{
		ll a, b, c;
		cin >> a;
		if (a == 0)
		{
			cin >> b >> c;
			if (b > c)swap(b, c);
			cout << Sum(0, N - 1, b - 1, c - 1, 1) << "\n";
		}
		else if (a == 1)
		{
			ll diff = 0;
			cin >> b >> c;
			diff = c - arr[b];
			arr[b] = c;
			Update(0, N - 1, b - 1, 1, diff);
		}
	}
	return 0;
}