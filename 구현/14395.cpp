#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M;
map<long long, int>m;
void bfs()
{
	queue<pair<long long, string>>q; q.push({ N,"" }); m[N] = 1;
	while (!q.empty()) {
		long long cur = q.front().first; string s = q.front().second; q.pop();
		if (cur == M) { cout << s; return; }
		if (m[cur * cur] == 0) { m[cur * cur] = 1; q.push({ cur * cur ,s + '*' }); }
		if (m[cur + cur] == 0) { m[cur + cur] = 1; q.push({ cur + cur ,s + '+' }); }
		if (m[cur - cur] == 0) { m[cur - cur] = 1; q.push({ cur - cur ,s + '-' }); }
		if (cur != 0 && m[cur / cur] == 0) { m[cur / cur] = 1; q.push({ cur / cur ,s + '/' }); }
	}
	cout << "-1";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	if (N == M)cout << "0"; else bfs();
	return 0;
}

