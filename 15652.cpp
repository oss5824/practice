#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int* A;
bool* visit;
void dfs(int num, int val)
{
	if (val == m)
	{
		for (int i = 0; i < m; i++)printf("%d ", A[i]);
		printf("\n");
		return;
	}
	for (int i = num; i <= n; i++)
	{
		A[val] = i;
		visit[i] = true;
		dfs(i, val + 1);
		visit[i] = false;
	}
}
int main()
{
	cin >> n >> m;
	visit = new bool [n];
	A = new int[n];
	memset(visit, false, sizeof(bool) * n);
	memset(A, 0, sizeof(int) * n);
	dfs(1, 0);
	return 0;
}
