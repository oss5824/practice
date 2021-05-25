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
int N;
map<string, int>m;
int fin[1001];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) { string s; cin >> s; m[s] = i; }
	for (int i = 0; i < N; i++) { string s; cin >> s; fin[i] = m[s]; }
	int cnt = 0;
	for (int i = 0; i < N - 1; i++)
	{
		bool check = false;
		for (int j = i + 1; j < N; j++)if (fin[i] > fin[j]) { check = true; break; }
		if (check)cnt++;
	}
	cout << cnt;
	return 0;
}