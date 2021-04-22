#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<limits.h>
#define INF 987654321
using namespace std;
string s;
int N, result = INT_MIN;
int calculate(int idx)
{
	if (s[idx + 1] == '+')return (s[idx] - '0') + (s[idx + 2] - '0');
	else if (s[idx + 1] == '-')return  (s[idx] - '0') - (s[idx + 2] - '0');
	else if (s[idx + 1] == '*')return (s[idx] - '0') * (s[idx + 2] - '0');
}
int calculate2(int a, int b,char c)
{
	if (c == '+')return a + b;
	else if (c == '-')return a - b;
	else if (c == '*')return a * b;
}
void solve(int idx, int value,char c)
{
	if (idx >= N) { result = max(result, value); return; }
	int save_value = value;
	if (idx + 2 < N) {
		
		int sum = calculate(idx);
		value = calculate2(value, sum, c);
		solve(idx + 4, value, s[idx + 3]);
	}
	save_value = calculate2(save_value, s[idx] - '0', c);
	solve(idx + 2, save_value, s[idx + 1]);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> s;
	solve(0, 0, '+');
	cout << result;
	return 0;
}


