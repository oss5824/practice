#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n; vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)cin >> v[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b; int input = b;
		for (int j = 0; j < a; j++) input = v[input];
		cout << input << "\n";
	}
	return 0;
}

