#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF LLONG_MAX
typedef long long ll;
using namespace std;
ll Total, Win, Rate, result = INF;
bool check(ll m)
{
	ll newTotal = Total + m;
	ll newWin = Win + m;
	ll newRate = (newWin * 100) / newTotal;

	if (Rate < newRate)return true;
	else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> Total >> Win;
	Rate = (Win * 100) / Total;

	if (Rate >= 99) { cout << "-1"; return 0; }
	ll s = 0, e = 1000000000;
	while (s <= e) {
		ll m = (s + e) / 2;
		bool chk = check(m);
		if (chk) {
			e = m - 1; result = min(result, m);
		}
		else s = m + 1;
	}
	if (result == INF)cout << "-1"; else cout << result;
	return 0;
}


