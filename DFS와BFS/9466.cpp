#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int T, N, arr[100001];
bool cycle[100001];
bool visit[100001];
vector<int>v;
bool fin = true;
void dfs(int num)
{
	if (visit[num]){
		int len = v.size();
		bool check = false;
		for (int i = 0; i < len; i++) {
			if (v[i] == num) { check = true; }
			if (!check)continue;
			cycle[v[i]] = true;
		}
		fin = true;
		return;
	}
	visit[num] = true;
	v.push_back(num);
	dfs(arr[num]);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> N; memset(arr, 0, sizeof(arr)); memset(cycle, 0, sizeof(cycle));
		memset(visit, false, sizeof(visit)); v.clear();
		for (int i = 1; i <= N; i++)cin >> arr[i];
		for (int i = 1; i <= N; i++){
			v.clear(); fin = false; if (!visit[i])dfs(i);
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++)if (!cycle[i])cnt++;
		cout << cnt << "\n";
	}
	return 0;
}