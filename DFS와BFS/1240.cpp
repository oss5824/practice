#pragma warning(disable: 4996)
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
using namespace std;
string s;
int N, M;
int S, E;
bool fin = false;
int result;
vector<pair<int, int>>v[1001];
void dfs(int cur, int before, int sum)
{
	if (fin)return;
	if (cur == E) {
		result = sum;
		fin = true;
		return;
	}
	for (pair<int, int> next : v[cur]) {
		if (next.first == before)continue;
		dfs(next.first, cur, sum + next.second);
		if (fin)return;
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c; cin >> a >> b >> c; v[a].push_back({ b,c }); v[b].push_back({ a,c });
	}
	for (int i = 0; i < M; i++) {
		fin = false; result = 0;
		int a, b; cin >> a >> b; S = a, E = b;
		dfs(a, -1, 0); cout << result << "\n";
	}
	return 0;
}
