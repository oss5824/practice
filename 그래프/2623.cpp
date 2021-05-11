#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, T, K, level[1001];
vector<int>v[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> T; 
	vector<int>res;
	while (T--) {
		cin >> K;
		int arr[1001];
		cin >> arr[0];
		for (int i = 1; i < K; i++) { cin >> arr[i]; level[arr[i]]++; }
		for (int i = 0; i < K - 1; i++)v[arr[i]].push_back(arr[i + 1]);
	}
	queue<int>q;
	for (int i = 1; i <= N; i++)if (level[i] == 0)q.push(i);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		res.push_back(cur);
		for (int next : v[cur]) {
			if (--level[next] == 0)q.push(next);
		}
	}
	if (res.size() != N)cout << "0";
	else for (int i : res)cout << i << "\n";
	return 0;
}