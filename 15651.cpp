#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int>v;
void dfs(int num)
{
	if (num == m)
	{
		int len = v.size();
		for (int i = 0; i < len; i++)printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		v.push_back(i+1);
		dfs(num + 1);
		v.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	dfs(0);
	return 0;
}
