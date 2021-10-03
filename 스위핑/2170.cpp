#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>>arr;
typedef long long ll;
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; arr.assign(n, { 0,0 });
	for (int i = 0; i < n; i++)cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end(),cmp);
	pair<int, int>pos = { 2e9,2e9 };
	int result = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i].second <= pos.first) {
			pos = arr[i]; result += pos.second - pos.first;
		}
		else if (arr[i].first >= pos.first)continue;
		else {
			result += pos.first - arr[i].first; pos.first = arr[i].first;
		}
	}cout << result;
	return 0;
}
