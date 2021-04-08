#include <iostream>
int t, n; int M[12];
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	M[1] = 1, M[2] = 2, M[3] = 4;
	for (int i = 4; i <= 11; i++)M[i] = M[i - 3] + M[i - 2] + M[i - 1];
	cin >> t;
	while (t--) { cin >> n; cout << M[n] << "\n"; }
	return 0;
}

