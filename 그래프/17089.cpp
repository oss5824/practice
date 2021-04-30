#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
#define MAX 4000
using namespace std;
int N, M;
bool link[MAX + 1][MAX + 1];
vector<int>v[MAX + 1];
int result = INF;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	while (M--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
		link[a][b] = true; link[b][a] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (v[i].size() < 2)continue;
		int len = v[i].size();
		for (int j = 0; j < len - 1; j++)
			for (int k = j + 1; k < len; k++)
				if (link[v[i][j]][v[i][k]]){
					int sum = v[v[i][j]].size() - 2 + v[v[i][k]].size() - 2 + v[i].size() - 2;
					result = min(result, sum);
				}
	}
	result == INF ? cout << "-1" : cout << result;
	return 0;
}

