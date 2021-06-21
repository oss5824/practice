#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
using namespace std;
int N;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; vector<long long>v;
	for (int i = 0; i < N; i++) { long long a; cin >> a; v.push_back(a); }
	long long result = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) { if (v[i] == i + 1)continue; result += abs(v[i] - (i + 1)); }
	cout << result;
;	return 0;
}

