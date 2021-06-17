#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#include<string>
#include<queue>
#define INF 1e9
typedef unsigned long long ull;
using namespace std;
string s;
int N, M;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	priority_queue<ull, vector<ull>, greater<ull>>q;
	for (int i = 0; i < N; i++) { ull a; cin >> a; q.push(a); }
	while (M--) {
		ull a = q.top(); q.pop();
		ull b = q.top(); q.pop();
		q.push(a + b); q.push(a + b);
	}
	int len = q.size();
	ull sum = 0;
	for (int i = 0; i < len; i++) { sum += q.top(); q.pop(); }
	cout << sum;
	return 0;
}


