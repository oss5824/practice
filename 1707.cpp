#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
int T, V, E;
vector<int>* v;
bool* visit;
int* arr;
void bfs(int num)
{
	queue<int>q;
	q.push(num);
	int turn = 1;
	while (!(q.empty()))
	{
		int x = q.front();
		q.pop();
		int len = v[x].size();
		if (arr[x] == 1)turn = 2;
		else if (arr[x] == 2)turn = 1;
		for (int i = 0; i < len; i++)
			if (arr[v[x][i]] == 0)
			{
				arr[v[x][i]] = turn;
				q.push(v[x][i]);
			}
	}
}
bool check(int num)
{
	for (int i = 1; i <= V; i++)
	{
		int len = v[i].size();
		for (int j = 0; j < len; j++)if (arr[i] == arr[v[i][j]])return false;
	}
	return true;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> V >> E;
		v = new vector<int>[V + 1];
		arr = new int[V + 1];
		visit = new bool[V + 1];
		memset(arr, 0, sizeof(int) * (V + 1));
		memset(visit, false, sizeof(bool) * (V + 1));
		for (int j = 0; j < E; j++)
		{
			int a, b;
			cin >> a >> b;
			if (a != b)
			{
				v[a].push_back(b);
				v[b].push_back(a);
			}
		}
		for (int j = 1; j <= V; j++)sort(v[j].begin(), v[j].end());
		for (int j = 1; j <= V; j++)if (arr[j] == 0)bfs(j);
		bool val = check(1);
		if (val)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
