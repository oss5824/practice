#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
bool inQ[101];
using namespace std;
int main()
{
	int N, M, a; scanf("%d %d", &N, &M);
	vector<pair<pair<int, int>, int>>v;//추천수,순서,번호
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		if (!inQ[a]) {
			inQ[a] = true;
			if (v.size() == N) { inQ[v[0].second] = false; v.erase(v.begin()); }
			v.push_back({ {1, i}, a });
		}
		else {
			int len = v.size();
			for (int j = 0; j < len; j++) { if (v[j].second == a) { v[j].first.first++; break; } }
		}
		sort(v.begin(), v.end());
	}
	vector<int>res;
	for (pair<pair<int, int>, int>p : v)res.emplace_back(p.second);
	sort(res.begin(), res.end());
	for (int i : res)printf("%d ", i);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);