#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
typedef unsigned long long ull;
#define INF INT_MAX
using namespace std;
int N, result = INF;
int arr[21];
bool visit[21];
bool fin = false;
vector<int>v;
string s;
bool check()
{
	int len = v.size(), cnt = 0, level = 0;
	for (int i = 0; i < len; i++)
	{
		int sum = 0;
		int start = cnt;
		for (int j = i; j < len; j++)
		{
			sum += v[j];
			char c;
			if (sum > 0)c = '+';
			else if (sum == 0)c = '0';
			else c = '-';
			if (s[start++] != c)return false;
		}
		cnt = cnt + N - level;
		level++;
	}
	return true;
}
void solve(int num)
{
	if (fin == true)return;
	if (v.size() == N)
	{
		for (int i : v)cout << i << " ";
		fin = true;
		return;
	}
	for (int i = num; i <= 20; i++)
	{
		v.push_back(arr[i]);
		if (check())solve(num);
		if (fin == true)return;
		v.pop_back();
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> s;
	int a = -10;
	for (int i = 0; i <= 20; i++)arr[i] = a++;
	solve(0);
	return 0;
}
