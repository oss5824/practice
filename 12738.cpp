#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000001], M[1000001], idx[1000001], n, res;
vector<int>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n;for (int i = 0; i < n; i++)cin >> arr[i];
	v.push_back(arr[0]); idx[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (v.back() < arr[i]) { v.push_back(arr[i]); idx[i] = v.size(); }
		else { int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin(); v[index] = arr[i]; idx[i] = index + 1; }
	}cout << v.size();
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);