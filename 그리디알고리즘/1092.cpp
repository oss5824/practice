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
int N, M;
vector<int>v, w;
bool visit[10001];
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	int a;
	cin >> N;for (int i = 0; i < N; i++) { cin >> a; v.push_back(a); }
	cin >> M;for (int i = 0; i < M; i++) { cin >> a; w.push_back(a); }
	sort(v.begin(), v.end(), greater<int>()); sort(w.begin(), w.end(), greater<int>());
	if (v[0] < w[0]) { cout << "-1"; return 0; }
	int w_idx = 0, min = 0;
	while (w_idx < M) {
		for (int i = 0; i < N; i++) {
			while (w_idx < M && visit[w_idx])w_idx++;
			if (w_idx == M)break;
			if (w[w_idx] <= v[i]) { visit[w_idx] = true;  w_idx++; if (w_idx == M)break; }
			else {
				int idx = w_idx;
				while (idx < M && (visit[idx] || w[idx] > v[i]))idx++;
				if (idx == M)break;
				visit[idx] = true;
			}
		}
		min++;
	}
	cout << min;
;	return 0;
}

