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
int N; 
ll sum;
vector<pair<int, pair<int, int>>>v;
ll Color[200001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	vector<ll>result(N, 0);
	for (int i = 0; i < N; i++) { int a, b; cin >> a >> b; v.push_back({ b,{a,i} }); }
	stable_sort(v.begin(), v.end());
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		int sz = v[i].first, color = v[i].second.first;
		if (i != 0 && v[i].first == v[i - 1].first){
			if (v[i].second.first != v[i - 1].second.first) {
				result[v[i].second.second] = sum - Color[color] - sz * cnt; cnt++;
			}
			else { result[v[i].second.second] = result[v[i - 1].second.second]; cnt++; }
		}
		else { result[v[i].second.second] = sum - Color[color]; cnt = 1; }
		sum += sz;
		Color[color] += sz;
	}
	for (ll i : result)cout << i << "\n";
	return 0;
}


