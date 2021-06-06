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
#define INF INT_MAX
typedef unsigned long long ull;
using namespace std;
int T, N;
vector<pair<int, int>>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N; v.clear();
		for (int i = 0; i < N; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int value = INF, cnt = 0;
		for (int i = 0; i < N; i++) {
			if (v[i].second < value) { cnt++; value = v[i].second; }
		}
		cout << cnt << "\n";
	}
	return 0;
}
