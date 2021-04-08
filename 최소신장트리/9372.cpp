#include <iostream>
using namespace std;
int T, n, m, a, b;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)cin >> a >> b;
		cout << n - 1 << "\n";
	}
	return 0;
}