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
int N, M;
int Sum[100001];;
vector<int>v[100001];

void dfs(int cur)
{
	for (int next : v[cur]) { Sum[next] += Sum[cur]; dfs(next); }
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) { int a; cin >> a; if (a != -1) { v[a].push_back(i); } }
	for (int i = 0; i < M; i++) { int a, b; cin >> a >> b; Sum[a] += b; }
	dfs(1);
	for (int i = 1; i <= N; i++)cout << Sum[i] << " ";
	return 0;
}


