#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
long long a, b;
void bfs()
{
	queue <pair< long long, long long >> q; q.push({ a ,1 }); ; long long dist = -1;
	while (!q.empty()) {
		long long cur = q.front().first, cur_dist = q.front().second; q.pop();
		if (cur == b) { dist = cur_dist; break; }
		string s = to_string(cur); s.append("1");
		long long val1 = stol(s), val2 = cur * 2;
		if (val1 <= b) { q.push({ val1,cur_dist + 1 }); }
		if (val2 <= b) { q.push({ val2,cur_dist + 1 }); }
	}cout << dist;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> a >> b; bfs();
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);