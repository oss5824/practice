#include <iostream>
#include <vector>
using namespace std;

int* store;
bool* visit;
vector<int> v;
int n, m;
void dfs(int num)
{
	if (num == m)
	{
		int len = v.size();
		for (int i = 0; i < len; i++)printf("%d ", v[i]);
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i])continue;
		visit[i] = true;
		v.push_back(store[i]);
		dfs(num + 1);
		v.pop_back();
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
	dfs(0);
	return 0;
}
