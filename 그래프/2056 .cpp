#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, result;
int level[10001], Time[10001], M[10001];
vector<int>v[101];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Time[i];
		int K, a;
		cin >> K;
		while (K--) { cin >> a; v[a].push_back(i); level[i]++; }
	}
	queue<int>q;
	for (int i = 1; i <= N; i++)if (level[i] == 0) { q.push(i); M[i] = Time[i]; }

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int next : v[cur])
		{
			if (--level[next] == 0)q.push(next);
			M[next] = max(M[cur] + Time[next], M[next]);
		}
	}
	for (int i = 1; i <= N; i++)result = max(result, M[i]);
	cout << result;
	return 0;
}