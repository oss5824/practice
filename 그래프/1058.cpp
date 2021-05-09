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
#define INF 1e9
using namespace std;
int N, result;
int Map[50][50];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char a;
			cin >> a;
			if (a == 'Y') { Map[i][j] = 1; Map[j][i] = 1; }
			else { Map[i][j] = INF; Map[j][i] = INF; }
		}
	}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (Map[i][j] > Map[i][k] + Map[k][j])Map[i][j] = Map[i][k] + Map[k][j];
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j)continue;
			if (Map[i][j] <= 2)cnt++;
		}
		result = max(cnt, result);
	}
	cout << result;
	return 0;
}