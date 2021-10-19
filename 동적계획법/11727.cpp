#include <iostream>
using namespace std;
int n, M[1001];
int DP(int x)
{
	if (x == 1)return 1;
	if (x == 2)return 3;
	if (M[x] != 0)return M[x] % 10007;
	return M[x] = (DP(x - 1) + 2 * DP(x - 2)) % 10007;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> n; cout << DP(n);
	return 0;
}
