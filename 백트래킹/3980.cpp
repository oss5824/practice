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
typedef unsigned long long ull;
int T, Map[11][11];
int result;
bool check[11];
vector<int>v;
void solve(int num)
{
	if (num == 11) {
		int sum = 0; for (int i : v)sum += i;
		result = max(sum, result);
		return;
	}
	for (int i = 0; i < 11; i++)
	{
		if (check[i] || Map[num][i] == 0)continue;
		check[i] = true;
		v.push_back(Map[num][i]);
		solve(num + 1);
		v.pop_back();
		check[i] = false;
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(check, false, sizeof(check)); result = 0; memset(Map, 0, sizeof(Map));
		v.clear();
		for (int i = 0; i < 11; i++)for (int j = 0; j < 11; j++)cin >> Map[i][j];
		solve(0);
		cout << result << "\n";
	}
	return 0;
}