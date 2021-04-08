#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
map<ll, int>m;
bool cmp(pair<ll, int>a, pair<ll, int>b)
{
	if (a.second < b.second)return true;
	else if (a.second > b.second)return false;
	else return a.first > b.first;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; ll a; while (n--) { cin >> a; m[a]++; }
	vector<pair<ll, int>>v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp); cout << v[v.size() - 1].first;
	return 0;
}