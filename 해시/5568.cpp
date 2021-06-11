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
typedef long long ll;
using namespace std;
int N, K, cnt, arr[10];
bool visit[10];
vector<int>v;
set<string>hash_set;
void solve(int num)
{
	if (v.size() == K) {
		string s; for (int i : v)s += to_string(i);
		if (hash_set.count(s) == 0) { hash_set.insert(s); cnt++; }
		return;
	}
	for (int i = num; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(arr[i]);
			solve(num);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K; for (int i = 0; i < N; i++)cin >> arr[i];
	solve(0);
	cout << cnt;
	return 0;
}


