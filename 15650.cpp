#include <iostream>
using namespace std;
int* store;
bool* visit;
int n, m;
void dfs(int num, int index)
{
	if (num == m)
	{
		for (int i = 0; i < n; i++)if(visit[i])printf("%d ", store[i]);
		printf("\n");
	}
	for (int i = index; i < n; i++)
	{
		if (visit[i])continue;
		visit[i] = true;
		dfs(num + 1, i + 1);
		visit[i] = false;
	}
}
int main()
{
	cin >> n >> m;
	store = new int[n];
	visit = new bool[n];
	for (int i = 0; i < n; i++)
	{
		store[i] = i + 1;
		visit[i] = false;
	}
	dfs(0, 0);
	return 0;
}
