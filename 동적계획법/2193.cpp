#include <iostream>
unsigned long long n, M[91];
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	M[1] = 1, M[2] = 1;
	for (int i = 3; i <= 90; i++)M[i] = M[i - 2] + M[i - 1];
	cin >> n; cout << M[n];
	return 0;
}

