#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<limits.h>
#define INF 987654321
using namespace std;
int N, all, cnt;
int arr[20];
bool visit[20], M[2000010];
vector<int>v;
void solve(int num)
{
	int sum = 0;
	for (int i : v)sum += arr[i];
	M[sum] = true;
	if (v.size() == N) { return; }
	for (int i = num; i < N; i++)
	{
		if (!visit[i])
		{
			v.push_back(i);
			visit[i] = true;
			solve(i);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;	for (int i = 0; i < N; i++)cin >> arr[i];
	solve(0);
	for (int i = 1;; i++)if (!M[i]) { cout << i; break; }
	return 0;
}


