#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string s1, s2;
int M[1001][1001];
int LCS(int x, int y)
{
	if (x == 0 || y == 0)return 0;
	if (M[x][y] != -1)return M[x][y];
	if (s1[x - 1] == s2[y - 1])M[x][y] = LCS(x - 1, y - 1) + 1;
	else M[x][y] = max(LCS(x - 1, y), LCS(x, y - 1));
	return M[x][y];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s1 >> s2; memset(M, -1, sizeof(M)); cout << LCS(s1.length(), s2.length());
	return 0;
} 
