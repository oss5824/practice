#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M;
vector<int>v;
bool visit[9];
void solve(int num)
{
	if (v.size() == N) { for (int i : v)cout << i << " "; cout << "\n"; return; }
	for (int i = num; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			solve(num);
			visit[i] = false;
			v.pop_back();
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; solve(1);
	return 0;
}


