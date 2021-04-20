#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int T, N;
char ch[10];
vector<int>v;
bool visit[10];
int cnt = 0;
vector<int>res1, res2;
bool check()
{
	int len = v.size();
	for (int i = 0; i < len - 1; i++){
		if (ch[i] == '<' && v[i] > v[i + 1])return false;
		else if (ch[i] == '>' && v[i] < v[i + 1])return false;	
	}
	return true;
}
void solve(int num)
{
	if (v.size() == N + 1)
	{
		if (res1.size() == 0)res1 = v; else res2 = v;
		return;
	}
	for (int i = num; i <= 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			if (check())solve(num);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; 
	for (int i = 0; i < N; i++) { char c; cin >> c; ch[i] = c; }
	solve(0); 
	for (int i : res2)cout << i;
	cout << "\n";
	for (int i : res1)cout << i;
	return 0;
}


