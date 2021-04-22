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
int N, result;
int Hit[50][10];
vector<int>v;
bool visit[10];
bool check()
{
	if (v.size() < 4)return true;
	if (v[3] == 1)return true; else return false;
}
void solve(int num)
{
	if (v.size() == 9)
	{
		int start = 0, sum = 0;
		for (int i = 0; i < N; i++)
		{
			int out = 0;
			int one = 0, two = 0, three = 0;
			while (out < 3)
			{
				if (Hit[i][v[start]] == 0)out++;
				else if (Hit[i][v[start]] == 1)
				{
					if (three == 1) { three = 0; sum++; }
					if (two == 1) { two = 0; three = 1; }
					if (one == 1) { one = 0; two = 1; }
					one = 1;
				}
				else if (Hit[i][v[start]] == 2)
				{
					if (three == 1) { three = 0; sum++; }
					if (two == 1) { two = 0; sum++; }
					if (one == 1) { one = 0; three = 1; }
					two = 1;
				}
				else if (Hit[i][v[start]] == 3)
				{
					if (three == 1) { three = 0; sum++; }
					if (two == 1) { two = 0; sum++; }
					if (one == 1) { one = 0; sum++; }
					three = 1;
				}
				else if (Hit[i][v[start]] == 4)
				{
					if (three == 1) { three = 0; sum++; }
					if (two == 1) { two = 0; sum++; }
					if (one == 1) { one = 0; sum++; }
					sum++;
				}
				start++; if (start > 8)start = 0;
			}
		}
		result = max(result, sum);
		return;
	}
	for (int i = num; i < 10; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			if (check())solve(num);
			visit[i] = false;
			v.pop_back();
		}
	}

}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; 
	for (int i = 0; i < N; i++)for (int j = 1; j <= 9; j++)cin >> Hit[i][j];
	solve(1);
	cout << result;
	return 0;
}


