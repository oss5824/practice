#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#include<string>
#include<queue>
#define INF 1e9
typedef unsigned long long ull;
using namespace std;
int N, len, cnt = 0;
string tmp, s;
bool prime[10000001];
bool visit[10000001];
bool visitNum[7];
void solve(int num)
{
	if (tmp.size() == len)return;
	for (int i = num; i < len; i++) {
		if (!visitNum[i])
		{
			tmp.push_back(s[i]); visitNum[i] = true;
			int val = stoi(tmp);
			if (prime[val] && !visit[val]) { cnt++; visit[val] = true; }
			solve(num);
			tmp.pop_back(); visitNum[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	memset(prime, true, sizeof(prime));
	int sqrtNum = sqrt(10000000);
	prime[1] = false; prime[0] = false;
	for (int i = 2; i <= sqrtNum; i++)
	{
		if (!prime[i])continue;
		for (int j = i + i; j <= 10000000; j += i) { prime[j] = false; }
	}
	while (N--) {
		cin >> s; tmp = ""; len = s.length(); memset(visit, false, sizeof(visit)); cnt = 0;
		memset(visitNum, false, sizeof(visitNum));
		solve(0);	
		cout << cnt << "\n";
	}
	return 0;
}


