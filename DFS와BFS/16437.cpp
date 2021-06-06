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
#define INF ll_MAX
typedef long long ll;
using namespace std;
ll N, level[123460], value[123460];
pair<char, pair<ll, ll>>v[123460];


int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		char c; ll a, b; cin >> c >> a >> b;
		v[i] = { c,{a,b} };
		level[b]++;
	}
	queue <int> q;
	for (int i = 2; i <= N; i++) { if (level[i] == 0)q.push(i); }
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == 1) {
			break;
		}
		char c = v[cur].first;
		ll cnt = v[cur].second.first, next = v[cur].second.second;
		if (c == 'S') {
			value[next] = value[next] + value[cur] + cnt;
			if (--level[next] == 0)q.push(next);
		}
		else if (c == 'W') {
			if (value[cur] - cnt >= 0){
				value[next] = value[next] + value[cur] - cnt; 
			}
			if (--level[next] == 0)q.push(next);
		}
	}cout << value[1];
	return 0;
}
