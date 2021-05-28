#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, K;
int cost[10001], par[10001], result[10001];
int Find(int x) { if (x == par[x])return x; else return par[x] = Find(par[x]); }
void Merge(int x, int y)
{
	x = Find(x); y = Find(y); if (x == y)return;
	if (x > y)par[x] = y;
	else par[y] = x;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K; fill(result, result + N + 1, INF);
	for (int i = 1; i <= N; i++) { cin >> cost[i]; par[i] = i; }
	while (M--){
		int a, b; cin >> a >> b; Merge(a, b);
	}
	int sum = 0;
	for (int i = 1; i <= N; i++)result[Find(par[i])] = min(result[Find(par[i])], cost[i]);
	for (int i = 1; i <= N; i++)if (result[i] != INF)sum += result[i];
	if (K >= sum)cout << sum;
	else cout << "Oh no";
	return 0;
}