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
#define INF ll_MAX
typedef long long ll;
using namespace std;
int N, K;
vector<pair<pair<int, int>, pair<int, int>>>v;
bool cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
	if (a.first.second > b.first.second)return true;
	else if (a.first.second < b.first.second)return false;
	else {
		if (a.second.first > b.second.first)return true;
		else if (a.second.first < b.second.first)return false;
		else {
			if (a.second.second > b.second.second)return true;
			else if (a.second.second < b.second.second)return false;
			else return a.first.first < b.first.first;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d; v.push_back({ {a,b},{c,d} });
	}
	sort(v.begin(), v.end(), cmp);
	int result = 0;
	int gold = -1, silver = -1, bronze = -1;
	for (int i = 0; i < N; i++) {
		if (gold == v[i].first.second && v[i].second.first == silver && v[i].second.second == bronze) {
		}
		else {
			result=i;
			gold = v[i].first.second, silver = v[i].second.first, bronze = v[i].second.second;
			result++;
		}
		if (K == v[i].first.first)break;
	}
	cout << result;
	return 0;
}
