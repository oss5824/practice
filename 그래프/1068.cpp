#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N;
int parent[50];
bool check[50];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; int root = 0;
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a; if (a == -1) { parent[i] = i;root=i; }
		else parent[i] = a;
	}
	int removal;
	cin >> removal; parent[removal] = removal; check[removal] = true;
	for (int i = 0; i < N; i++)
	{
		int start = i;
		while (parent[start] != start)start = parent[start];
		if (start == removal) { check[i] = true; continue; }
		check[parent[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)if (!check[i]) cnt++;

	(cnt == 0 && removal != root) ? cout << "1" : cout << cnt;
	return 0;
}

