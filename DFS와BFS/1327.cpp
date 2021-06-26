#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#define INF 1e9
using namespace std;
string s, result;
int N, K;
set<string>visit;
void bfs()
{
	queue<pair<string, int>>q; q.push({ s,0 }); visit.insert(s);
	while (!q.empty()) {
		string cur = q.front().first; int curD = q.front().second; q.pop();
		if (cur == result) { cout << curD; return; }
		for (int i = 0; i <= N - K; i++) {
			string first = cur.substr(0, i);
			string third = cur.substr(i + K);
			string second = cur.substr(i, K);
			reverse(second.begin(), second.end());
			string next = first + second + third;
			if (visit.count(next) == 0) { q.push({ next,curD + 1 }); visit.insert(next); }
		}
	}
	cout << "-1";
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K; char a;
	for (int i = 1; i <= N; i++) { cin >> a; s.push_back(a); result.push_back((char)('0' + i)); }

	bfs();

	return 0;
}
