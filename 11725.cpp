#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
bool* visit;
int* parent;
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	vector<int>* v = new vector<int>[n + 1]; visit = new bool[n + 1]; parent = new int[n + 1];
	memset(visit, false, sizeof(bool) * (n + 1)); memset(parent, 0, sizeof(int) * (n + 1));
	for (int i = 0; i < n - 1; i++) { cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	queue<int>q; q.push(1); visit[1] = true;
	while (!q.empty())
	{
		int cur = q.front(), len = v[cur].size();
		q.pop();
		for (int i = 0; i < len; i++)
		{
			int val = v[cur][i];
			if (!visit[val]) { q.push(val); visit[val] = true; parent[val] = cur; }
		}
	}
	for (int i = 2; i <= n; i++)cout << parent[i] << "\n";
	return 0;
}