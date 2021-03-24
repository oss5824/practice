#include <iostream>
#include <algorithm>
using namespace std;
int n, m, M[100001], arr[101];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	cin >> n>> m; for (int i = 1; i <= n; i++)cin >> arr[i];
	M[0] = 1;
	for (int i = 1; i <= n; i++)for (int j = arr[i]; j <= m; j++)M[j] += M[j - arr[i]];
	cout << M[m];
	return 0;
}

