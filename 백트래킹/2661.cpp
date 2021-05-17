#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N;
string s;
bool fin = false;
bool check()
{
	int len = s.length();
	int sub_len = len / 2;
	for (int i = 1; i <= (sub_len); i++)if (s.substr(len - i, i) == s.substr(len - (2 * i), i))return false;
	return true;
}
void solve(int num)
{
	if (fin)return;
	if (s.size() == N) { cout << s << "\n"; fin = true; return; }
	for (int i = num; i <= 3; i++)
	{
		s += (i + '0');
		if (check())solve(num);
		if (fin)return;
		s.pop_back();
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	solve(1);
	return 0;
}