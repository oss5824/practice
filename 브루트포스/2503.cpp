#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, M, cnt;
string tmp;
vector<pair<string, pair<int, int>>>v;
int arr[9] = { 1,2,3,4,5,6,7,8,9 };
bool visit[9];
void solve(int num)
{
	if (tmp.size() == 3)
	{
		for (pair<string, pair<int, int>>p : v)
		{
			string s_in = p.first;
			int check_strike = 0, check_ball = 0;
			int strike = p.second.first, ball = p.second.second;
			if (tmp[0] == s_in[0])check_strike++;
			else if (tmp[0] == s_in[1] || tmp[0] == s_in[2])check_ball++;
			if (tmp[1] == s_in[1])check_strike++;
			else if (tmp[1] == s_in[0] || tmp[1] == s_in[2])check_ball++;
			if (tmp[2] == s_in[2])check_strike++;
			else if (tmp[2] == s_in[0] || tmp[2] == s_in[1])check_ball++;
			if (check_strike == strike && check_ball == ball) { continue; }
			else return;
		}
		cnt++;
		return;
	}
	for (int i = num; i < 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			tmp.push_back(arr[i]+'0');
			solve(num);
			visit[i] = false;
			tmp.pop_back();
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s; int a, b; cin >> s >> a >> b;
		v.push_back({ s,{a,b} });
	}
	solve(0);
	cout << cnt;
	return 0;
}