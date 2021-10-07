#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
struct edge {
	int x, y, z, i;
};
struct point {
	int a, b, c;
};
edge v[100001];
vector<point>vp;
int par[100001];
long long res;
int find(int a)
{
	if (par[a] == a)return a;
	return par[a] = find(par[a]);
}
bool cmpX(edge a, edge b) { return a.x < b.x; }
bool cmpY(edge a, edge b) { return a.y < b.y; }
bool cmpZ(edge a, edge b) { return a.z < b.z; }
bool cmpC(point a, point b) { return a.c < b.c; }
bool merge(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b)return false;
	par[b] = a;
	return true;
}
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N; cin >> N;
	for (int i = 0; i < N; i++)cin >> v[i].x >> v[i].y >> v[i].z, v[i].i = i, par[i] = i ;
	sort(v, v + N, cmpX);
	for (int i = 0; i < N - 1; i++)vp.push_back({ v[i].i,v[i + 1].i,abs(v[i + 1].x - v[i].x) });
	sort(v, v + N, cmpY);
	for (int i = 0; i < N - 1; i++)vp.push_back({ v[i].i,v[i + 1].i,abs(v[i + 1].y - v[i].y) });
	sort(v, v + N, cmpZ);
	for (int i = 0; i < N - 1; i++)vp.push_back({ v[i].i,v[i + 1].i,abs(v[i + 1].z - v[i].z) });
	sort(vp.begin(), vp.end(), cmpC);
	int len = vp.size(), cnt = 0;
	for (int i = 0; i < len; i++) {
		if (merge(vp[i].a, vp[i].b)) {
			res += vp[i].c; cnt++;
			if (cnt == N - 1)break;
		}
	}cout << res;
}
