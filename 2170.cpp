#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>>arr;
typedef long long ll;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; arr.assign(n, { 0,0 }); 
	for (int i = 0; i < n; i++)cin >> arr[i].first >> arr[i].second;
	stable_sort(arr.begin(), arr.end());
	int start = arr[0].first, end = arr[0].second; ll result = end - start;
	for (int i = 1; i < n; i++)
	{
		int n_start = arr[i].first, n_end = arr[i].second;
		if (start <= n_start && n_end <= end)continue;
		else if (n_start == start) { if (end < n_end) { result += n_end - end; end = n_end; } }
		else
		{
			if (n_start <= end) { result += n_end - end; end = n_end; }
			else { result += n_end - n_start; start = n_start; }
		}
	}
	cout << result << "\n";
	return 0;
}
