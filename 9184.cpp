#include<iostream>
#include<cstring>
using namespace std;
int M[51][51][51];
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	if (M[a][b][c] != -1)return M[a][b][c];
	if (a > 20 or b > 20 or c > 20) return M[a][b][c] = w(20, 20, 20);
	if (a < b && b < c)return M[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return M[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while(1)
	{
		int a, b, c; cin >> a >> b >> c; memset(M, -1, sizeof(M));
		if (a == -1 && b == -1 && c == -1)break;
		cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << w(a, b, c) << "\n";
	}
	return 0;
}

