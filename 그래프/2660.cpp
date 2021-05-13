#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, Map[51][51], result = INF;
vector<int>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			Map[i][j] = (i == j) ? 0 : INF;
	while (1){
		int a, b; cin >> a >> b; if (a == -1 && b == -1)break;
		Map[a][b] = 1; Map[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (Map[i][j] > Map[i][k] + Map[k][j])Map[i][j] = Map[i][k] + Map[k][j];

	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)sum = max(sum, Map[i][j]);
		if (result > sum)
		{
			v.clear(); result = sum;
			v.push_back(i);
		}
		else if (result == sum) { v.push_back(i); }
	}
	cout << result << " " << v.size() << "\n";
	for (int i : v)cout << i << " ";
	return 0;
}