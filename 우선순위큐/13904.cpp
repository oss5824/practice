#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int N, s;
pair<int,int> v[1001];
bool cmp(pair<int, int> a, pair<int, int> b) { if (a.first == b.first)return a.second > b.second; return a.first < b.first; }
int main()
{
	scanf("%d", &N); priority_queue<pair<int, int>>q;
	for (int i = 0; i < N; i++) scanf("%d %d", &v[i].first, &v[i].second);
	sort(v, v + N, cmp);
	for (int i = 0, d, w; i < N; i++) {
		d = v[i].first, w = -v[i].second;
		if (q.size() < d)q.push({ w,d });
		else if (q.top().first > w) q.pop(), q.push({ w,d });
	}while (!q.empty())s += q.top().first, q.pop();
	printf("%d", -s);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
