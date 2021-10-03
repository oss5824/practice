#include<iostream>
#include<set>
#include<queue>
using namespace std;
long long n, k, cnt, res, a, dx[2] = { -1,1 };
queue<pair<int, int>>q;
set<int>s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	while (n--)cin >> a, q.push({ a,a }), s.insert(a);

	while (!q.empty()) {
		int x = q.front().first, mid = q.front().second; q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			if (s.count(nx) == 1)continue;
			s.insert(nx); cnt++; res += abs(mid - nx); q.push({ nx,mid });
			if (cnt == k) {cout << res; return 0;}
		}
	}
}