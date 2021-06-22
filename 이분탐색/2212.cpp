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
int N, K;
vector<int>v, dist;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	int a; cin >> N >> K; for (int i = 0; i < N; i++) { cin >> a; v.push_back(a); }
	if (N <= K) { cout << "0"; return 0; }
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++) {
		int distance = v[i + 1] - v[i]; dist.push_back(distance);
	}
	sort(dist.begin(), dist.end(), greater<int>());
	for (int i = 0; i < K - 1; i++)dist[i] = 0;
	int sum = 0;
	for (int i = 0; i < N - 1; i++)sum += dist[i];
	cout << sum;
;	return 0;
}

