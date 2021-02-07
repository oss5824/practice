#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, a, b, r; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b; r = -1;
		int res_a = a, res_b = b;
		if (a < b) { int tmp = a; a = b; b = tmp; }
		while (r != 0) { r = a % b; a = b; b = r; }
		cout << ((res_a * res_b) / a) << "\n";
	}
	return 0;
}