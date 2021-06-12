#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
typedef long long ll;
using namespace std;
int N, T, G;
bool visit[100000];
void bfs()
{
	queue<pair<int, int>>q; q.push({ N,0 }); visit[N] = true;
	while (!q.empty()) {
		int cur = q.front().first, curT = q.front().second; q.pop();
		if (curT > T)break;
		if (cur == G) { cout << curT; return; }
		int nextA = cur + 1;
		if (nextA < 100000) {
			if (!visit[nextA]) { q.push({ nextA,curT + 1 }); visit[nextA] = true; }
		}
		int nextB = cur * 2;
		if (nextB != 0 && nextB < 100000) {
			string s = to_string(nextB);
			s[0] = s[0] - 1;
			nextB = stoi(s);
			if (!visit[nextB]) { q.push({ nextB,curT + 1 }); visit[nextB] = true; }
		}
	}
	cout << "ANG";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> T >> G;
	if (N > G)cout << "ANG";
	else bfs();
	return 0;
}


