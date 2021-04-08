#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector<int>v;
int arr[1000001];
int index[1000001];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, len;
	stack<int>s;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i]; 
	v.push_back(arr[0]); index[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (v.back() < arr[i]) { v.push_back(arr[i]); index[i] = v.size(); }
		else
		{
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
			index[i] = idx + 1;
		}
	}
	len = v.size();
	printf("%d\n", len);
	for (int i = n - 1; i >= 0 && len > 0; i--)if (len == index[i]) { s.push(arr[i]); len--; }
	while (!s.empty()) { printf("%d ", s.top()); s.pop(); }
	return 0;
}