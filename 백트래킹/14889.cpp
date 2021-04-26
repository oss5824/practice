#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 1000000000
using namespace std;
int N, arr[20][20];
bool visit[20];
vector<int>v;
int result = INF;
void solve(int num)
{
	if (v.size() == N / 2)
	{
		vector<int>tmp;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < N; i++)if (!visit[i])tmp.push_back(i);
		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < N / 2; j++)
			{
				sum1 += arr[v[i]][v[j]];
				sum2 += arr[tmp[i]][tmp[j]];
			}
		result = min(result, abs(sum1 - sum2));
		return;
	}
	for (int i = num; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			solve(i);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> arr[i][j];
	solve(0); cout << result;
	return 0;
}