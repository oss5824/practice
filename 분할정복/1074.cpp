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
#define INF INT_MAX
using namespace std;
int N, R, C;
int value;

void solve(int n, int x, int y)
{
	if (n == 2)
	{
		if (x == C && y == R) { cout << value; return; }
		value++;
		if (x + 1 == C && y == R) { cout << value; return; }
		value++;
		if (x == C && y + 1 == R) { cout << value; return; }
		value++;
		if (x + 1 == C && y + 1 == R) { cout << value; return; }
		value++;
		return;
	}
	if (x <= C && C < x + n && y <= R && R < y + n)
	{
		solve(n / 2, x, y);
		solve(n / 2, x + n / 2, y);
		solve(n / 2, x, y + n / 2);
		solve(n / 2, x + n / 2, y + n / 2);
	}
	else value += n * n;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> R >> C;
	solve(pow(2, N), 0, 0);
	return 0;
}

