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
int N, M, T, a;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		set<int>s;
		cin >> N; for (int i = 0; i < N; i++) { cin >> a; s.insert(a); }
		cin >> M; while (M--) { cin >> a; cout << s.count(a) << "\n"; }
	}
	return 0;
}