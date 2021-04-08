#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int>v[100001];
bool visit[100001];
int M[100001];
int dfs(int num)
{
	visit[num] = true;
	int len = v[num].size();
	for (int i = 0; i < len; i++)if (!visit[v[num][i]])M[num] += dfs(v[num][i]);
	return M[num];
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, R, Q, a;
	memset(M, 1, sizeof(M));
	cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) { M[i] = 1; int a, b; cin >> a >> b; v[a].push_back(b); v[b].push_back(a); }
	M[N] = 1;
	dfs(R);
	for (int i = 0; i < Q; i++) { cin >> a; cout << M[a] << "\n"; }
	return 0;
}