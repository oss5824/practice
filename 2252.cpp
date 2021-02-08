#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m; 
	vector<int>* v = new vector<int>[n + 1];
	vector<int>level(n + 1, 0);
	for (int i = 0; i < m; i++) { cin >> a >> b; v[a].push_back(b); level[b]++; }
	queue<int>q;
	for (int i = 1; i <= n; i++)if (level[i] == 0)q.push(i);
	for (int i = 1; i <= n; i++)
	{
		if (q.empty()) { break; }
		int cur = q.front(), len = v[cur].size();
		cout << cur << " ";
		q.pop();
		for (int j = 0; j < len; j++)
		{
			level[v[cur][j]]--;
			if (level[v[cur][j]] == 0)q.push(v[cur][j]);
		}
	}
	return 0;
}
