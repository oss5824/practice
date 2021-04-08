#include <iostream>
using namespace std;
int t, n, M[10001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); cin >> t;
	while (t--){
		cin >> n; fill(M, M + n + 1, 0); M[0] = 1;
		for (int i = 1; i <= 3; i++)for (int j = i; j <= n; j++)M[j] += M[j - i];
		cout << M[n] << "\n";
	}
	return 0;
}
