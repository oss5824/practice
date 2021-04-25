#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 
using namespace std;
int N, a, s, m, d, arr[11];
string v, sv;
bool visit[44];
int res_max = -1000000001, res_min = 1000000001;
map<string, int>val;
void solve(int num)
{
	if (val[sv] == 0)val[sv]++; else return;
	if (sv.size() == N - 1)
	{
		int sum = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (sv[i - 1] == '+')sum += arr[i];
			else if (sv[i - 1] == '-')sum -= arr[i];
			else if (sv[i - 1] == '*')sum *= arr[i];
			else if (sv[i - 1] == '/')sum /= arr[i];
		}
		res_max = max(res_max, sum);
		res_min = min(res_min, sum);
		return;
	}
	for (int i = num; i < a + s + m + d; i++)
	{
		if (!visit[i]) {
			visit[i] = true;
			sv.push_back(v[i]);
			solve(num);
			visit[i] = false;
			sv.pop_back();
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> arr[i];
	cin >> a >> s >> m >> d;
	for (int i = 0; i < a; i++)v.push_back('+');
	for (int i = 0; i < s; i++)v.push_back('-');
	for (int i = 0; i < m; i++)v.push_back('*');
	for (int i = 0; i < d; i++)v.push_back('/');
	solve(0);
	cout << res_max << "\n" << res_min;
	return 0;
}