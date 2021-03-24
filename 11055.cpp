#include <iostream>
#include <algorithm>
using namespace std;
int n, m, M[1001], arr[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	cin >> n; for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		M[i] = arr[i];
		for (int j = 0; j < i; j++)if (arr[j] < arr[i])M[i] = max(M[i], M[j] + arr[i]);
		res = max(res, M[i]);
	}cout << res;

	return 0;
}

