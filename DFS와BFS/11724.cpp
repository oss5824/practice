#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int cnt;
int level[1001], parent[1001];
bool visit[1001];
int find(int num) { if (num == parent[num])return num; else return parent[num] = find(parent[num]); }
void merge(int a, int b)
{
	a = find(a); b = find(b); if (a == b)return;
	if (level[a] > level[b])swap(a, b);
	parent[a] = b;
	if (level[a] == level[b])level[b]++;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) { int a, b; cin >> a >> b; merge(a, b); }
	for (int i = 1; i <= N; i++) visit[find(parent[i])] = true;
	for (int i = 1; i <= N; i++)if (visit[i])cnt++;
	cout << cnt;
	return 0;
}

