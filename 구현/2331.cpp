#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<string>
#define INF 987654321
typedef unsigned long long ull;
using namespace std;
int N, M, cnt;
vector<int>v[501];
bool visit[300000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s;
	cin >> s >> M;
	vector<int>v; visit[stoi(s)] = true; v.push_back(stoi(s));
	while (1) {
		int val = 0, len = s.length();
		for (int i = 0; i < len; i++)val += pow(s[i] - '0', M);
		s = to_string(val);
		if (visit[stoi(s)])break;
		visit[val] = true; v.push_back(val);
	}for (int i : v) { if (i == stoi(s))break; cnt++; }cout << cnt;
	return 0;
}

