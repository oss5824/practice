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
int N, K;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K;
	queue<int>q;
	for (int i = 1; i <= N; i++)q.push(i);
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++) { int a = q.front(); q.pop(); q.push(a); }
		cout << q.front();
		q.pop();
		if (!q.empty())cout << ", ";
	}
	cout << ">";
	return 0;
}