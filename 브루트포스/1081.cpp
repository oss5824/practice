#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, result, arr[8];
bool visit[8];
vector<int>v;
void solve(int num)
{
	if (v.size() == N)
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum = sum + abs(arr[v[i]] - arr[v[i + 1]]);
		result = max(result, sum);
		return;
	}
	for (int i = num; i < N; i++)
	{
		if (!visit[i])
		{
			v.push_back(i);
			visit[i] = true;
			solve(num);
			visit[i] = false;
			v.pop_back();
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];
	solve(0); cout << result;
	return 0;
}

