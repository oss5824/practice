#include <iostream>
#include <cmath>
using namespace std;
int n, res;
int M[16];
bool check(int col)
{
	for (int i = 1; i < col; i++)if (M[col] == M[i] || abs(M[col] - M[i]) == abs(col - i))return false;
	return true;
}
void Queen(int col)
{
	if (col == n+1) { res++; return; }
	for (int row = 1; row <= n; row++)
	{
		M[col] = row;
		if (check(col)) { Queen(col + 1); }
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> n; Queen(1); cout << res;
	return 0;
}
