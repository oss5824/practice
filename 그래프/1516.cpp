#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, level[501], time[501], result[501];
vector<int>v[501];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> time[i];
		while (1) {
			cin >> a; if (a == -1)break;
			v[a].push_back(i); level[i]++;
		}
	}
	queue<int>q;
	for (int i = 1; i <= N; i++)if (level[i] == 0) { q.push(i); result[i] = time[i]; }
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : v[cur])
		{
			if (--level[next] == 0) q.push(next);
			if (time[next] + result[cur] > result[next])result[next] = time[next] + result[cur];
		}
	}for (int i = 1; i <= N; i++)cout << result[i] << "\n";
	return 0;
}

