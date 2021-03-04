#include<iostream>
using namespace std;
long long arr[100001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n; for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 1; i <= n; i++)arr[i] += arr[i - 1];
	cin >> m; while (m--) { cin >> a >> b; cout << arr[b] - arr[a - 1] << "\n"; }
	return 0;
}