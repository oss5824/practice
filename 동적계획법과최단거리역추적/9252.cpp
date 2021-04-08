#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[1003];
int M[1003][1003];
char one[1003], two[1003];
int dp(int idx_one, int idx_two)
{
	if (M[idx_one][idx_two] != -1)return M[idx_one][idx_two];
	if (one[idx_one - 1] == two[idx_two - 1])M[idx_one][idx_two] = dp(idx_one - 1, idx_two - 1) + 1;
	else M[idx_one][idx_two] = max(dp(idx_one - 1, idx_two), dp(idx_one, idx_two - 1));
	return M[idx_one][idx_two];
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	memset(M, -1, sizeof(M));
	cin >> one >> two;
	int len_one = strlen(one), len_two = strlen(two);
	for (int i = 0; i <= len_one; i++)M[i][0] = 0;
	for (int i = 0; i <= len_two; i++)M[0][i] = 0;
	printf("%d\n", dp(len_one, len_two));
	int y = len_one, x = len_two, cnt = 0;
	while (y != 0 || x != 0)
	{
		if (M[y][x] == M[y][x - 1])x--;
		else if (M[y][x] == M[y - 1][x])y--;
		else { arr[cnt++] = one[y - 1]; x--; y--; }
	}
	for (int i = cnt-1; i >= 0; i--)printf("%c", arr[i]);
	return 0;
}
