#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
typedef unsigned long long ull;
#define INF INT_MAX
using namespace std;
int N, result = INF;
int Map[10][10];
vector<int>v;
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> Map[i][j];
	for (int i = 0; i < N; i++)v.push_back(i);
	do {
		int sum = 0; bool check = false;
		for (int i = 0; i < N - 1; i++)
			if (Map[v[i]][v[i + 1]] == 0) { check = true; break; }
			else { sum += Map[v[i]][v[i + 1]]; }
		if (Map[v[N - 1]][v[0]] == 0)check = true;
		if (check)continue;
		sum += Map[v[N - 1]][v[0]];
		result = min(sum, result);
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
	return 0;
}
