#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < N; i++) { int a; cin >> a; q.push(a); }
	int result = 0;
	while (!q.empty())
	{
		if (q.size() == 1) { cout << result; break; }
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		result = result + a + b;
		q.push(a + b);
	}
	return 0;
}