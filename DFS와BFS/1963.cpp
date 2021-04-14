#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
bool notPrime[100001];
bool visit[100001];
int N;
int a, b;
void bfs()
{
	memset(visit, false, sizeof(visit)); visit[a] = true;
	queue<pair<int, int>>q; q.push({ a,0 });
	while (!q.empty()) {
		int cur = q.front().first, curD = q.front().second; q.pop();
		if (cur == b) { cout << curD << "\n"; return; }
		for (int i = 0; i < 4; i++)
		{
			string s = to_string(cur), curs = s;
			for (int j = 0; j <= 9; j++)
			{
				curs[i] = (char)(j + '0');
				int next = stoi(curs);
				if (next < 1000 || next >= 10000)continue;
				if (visit[next] || notPrime[next])continue;
				visit[next] = true;
				q.push({ next,curD + 1 });
			}
		}
	}
	cout << "Impossible\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 2; i <= 100000; i++)
	{
		if (notPrime[i])continue;
		for (int j = i * 2; j <= 100000; j += i)notPrime[j] = true;
	}
	while (N--) {
		cin >> a >> b; bfs();
	}
	return 0;
}

