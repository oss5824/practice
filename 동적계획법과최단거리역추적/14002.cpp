#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	pair<int, int>result(0, 0);
	stack <int>s;
	int M[1001] = { 0, };
	int arr[1001];
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		M[i] = 1;
		for (int j = 0; j < i; j++)if (arr[i] > arr[j])M[i] = max(M[i], M[j] + 1);
		if (M[i] > result.first)result = { M[i],i };
	}
	int end = result.second;
	printf("%d\n", result.first);
	s.push(arr[end]);
	for (int i = end - 1; i >= 0; i--)
		if (M[i] + 1 == M[end] && arr[i] < arr[end]) { end = i; s.push(arr[end]); }
	while (!s.empty()) { printf("%d ", s.top()); s.pop(); }
	return 0;
}