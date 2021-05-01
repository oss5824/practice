#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, M, cnt;
int par[51];
bool visit[51];
vector<int>v[51];
int Find(int x) { if (par[x] == x)return x; else return par[x] = Find(par[x]); }
void Merge(int x, int y)
{
	x = Find(x); y = Find(y); if (x == y)return;
	if (visit[x] == true)par[y] = x;
	else if (visit[y] == true)par[x] = y;
	else if (x < y)par[x] = y;
	else if (x > y)par[y] = x;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> cnt;
	int a, b;
	for (int i = 1; i <= N; i++)par[i] = i;
	for (int i = 0; i < cnt; i++) { cin >> a; visit[a] = true; }
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		bool check = false; int index = 0;
		for (int j = 0; j < a; j++) { cin >> b; v[i].push_back(b); }
		int len = v[i].size();
		for (int j = 0; j < len - 1; j++)
			for (int k = j + 1; k < len; k++)
				Merge(v[i][j], v[i][k]);
	}
	int val = 0;
	for (int i = 0; i < M; i++)
	{
		int len = v[i].size(); bool check = false;
		for (int j = 0; j < len; j++)if (visit[Find(par[v[i][j]])]) { check = true; break; }
		if (!check)val++;
	}
	cout << val;
	return 0;
}