#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, sz, cnt;
vector<int>v;
vector<int>res;
bool visit[10];
bool success = false;
bool check()
{
	int len = v.size();
	for (int i = 0; i < len - 1; i++)if (v[i] < v[i + 1])return false;
	return true;
}
void solve(int num)
{
	if (success) return;
	if (v.size() == sz) { if (cnt == N) { res = v; success = true; } cnt++; return; }
	for (int i = num; i <= 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			if (check()) solve(num);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	if (N <= 9) { cout << N; return 0; }
	for (sz = 1; sz <= 10; sz++)
	{
		v.clear(); memset(visit, false, sizeof(visit)); solve(0);
	}
	if (success)for (int i : res)cout << i;
	else cout << "-1";
	return 0;
}


