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
char arr[100001], t[400001];
char Init(ll s, ll e, ll n)
{
	if (s == e)return t[n] = arr[s];
	ll m = (s + e) / 2;
	char a = Init(s, m, 2 * n), b = Init(m + 1, e, 2 * n + 1), c;
	if (a == '0' || b == '0')c = '0';
	else if ((a == '-' && b == '+') || (a == '+' && b == '-'))c = '-';
	else c = '+';
	return t[n] = c;
}
char Mul(ll s, ll e, ll l, ll r, ll n)
{
	if (l > e || s > r)return '+';
	if (l <= s && e <= r)return t[n];
	ll m = (s + e) / 2;
	char a = Mul(s, m, l, r, 2 * n), b = Mul(m + 1, e, l, r, 2 * n + 1), c;
	if (a == '0' || b == '0')c = '0';
	else if ((a == '-' && b == '+') || (a == '+' && b == '-'))c = '-';
	else c = '+';
	return c;
}
void Update(ll s, ll e, ll idx, ll n, char c)
{
	if (!(s <= idx && idx <= e))return;
	if (s != e)
	{
		ll m = (s + e) / 2;
		Update(s, m, idx, 2 * n, c); Update(m + 1, e, idx, 2 * n + 1, c);
		char a = t[2 * n], b = t[2 * n + 1], c = '+';
		if (a == '0' || b == '0')c = '0';
		else if ((a == '-' && b == '+') || (a == '+' && b == '-'))c = '-';
		t[n] = c;
	}
	else
	{
		t[n] = c;
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (cin >> N)
	{
		cin >> M;
		string s;
		for (int i = 0; i < N; i++) {
			int a; cin >> a; if (a > 0)arr[i] = '+'; else if (a == 0)arr[i] = '0'; else arr[i] = '-';
		}
		Init(0, N - 1, 1);
		for (int i = 0; i < M; i++) {
			char c; cin >> c;
			ll a, b;
			if (c == 'P')
			{
				cin >> a >> b;
				s.push_back(Mul(0, N - 1, a - 1, b - 1, 1));
			}
			else if (c == 'C')
			{
				ll diff = 0;
				cin >> a >> b;
				if (b > 0)arr[a - 1] = '+'; else if (b == 0)arr[a - 1] = '0'; else arr[a - 1] = '-';
				Update(0, N - 1, a - 1, 1, arr[a - 1]);
			}
		}
		cout << s << "\n";
	}
	return 0;
}