#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N;
int len;
bool check(int num)
{
	if (num == 1 || num == 0)return false;
	for (int i = 2; i < num; i++)if (num % i == 0)return false;
	return true;
}
void dfs(int num, int val)
{
	if (val >= len)
	{
		cout << val << "\n";
		return;
	}
	for (int i = num; i <= 9; i++)
	{
		int nval;
		nval = val * 10 + i;
		if (check(nval))dfs(num, nval);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	len = pow(10, N - 1);
	dfs(0, 0);
	return 0;
}