#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
typedef unsigned long long ull;
#define INF INT_MAX
using namespace std;
int N, result = INF;
int arr[20][20];
bool visit[20];
vector<int>v;
void check()
{
	vector<int>s;
	for (int i = 0; i < N; i++)if (!visit[i])s.push_back(i);
	int sum_s = 0, sum_v = 0;
	int len = v.size();
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			sum_v += arr[v[i]][v[j]] + arr[v[j]][v[i]];
	len = s.size();
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			sum_s += arr[s[i]][s[j]] + arr[s[j]][s[i]];

	result = min(result, abs(sum_v - sum_s));
}
void solve(int num)
{
	if (v.size() == N - 1)return;
	for (int i = num; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			check();
			solve(i);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> arr[i][j];
	solve(0);
	cout << result;
	return 0;
}