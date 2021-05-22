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
vector<int>v;
vector<int>res;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; res.assign(N + 1, INF);
	int n = 1;
	while (1) {
		if (n * n > N)break;
		v.push_back(n * n); n++;
	}
	int len = v.size();
	res[0] = 0;
	for (int i = 0; i < len; i++)for (int j = v[i]; j <= N; j++)res[j] = min(res[j], res[j - v[i]] + 1);
	cout << res[N];
	return 0;
}