#include <iostream>
#include <algorithm>
using namespace std;
int n, res, M[1001][10];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	cin >> n; 
	for (int i = 0; i < 10; i++)M[1][i] = 1;
	for (int i = 2; i <= n; i++) 
		for (int j = 0; j < 10; j++)
			for (int k = j; k < 10; k++) { M[i][k] += M[i - 1][j]; M[i][k] %= 10007; }
	for (int i = 0; i < 10; i++)res += M[n][i];
	cout << res % 10007;
	return 0;
}

