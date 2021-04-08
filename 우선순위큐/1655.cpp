#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int, vector<int>,greater<int>>left_q;
	priority_queue<int, vector<int>, less<int>>right_q;
	int mid;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		if (left_q.size() < right_q.size())left_q.push(v);
		else right_q.push(v);
		if (!(left_q.empty()) && !(right_q.empty()))
		{
			if (left_q.top() < right_q.top())
			{
				int a = left_q.top();
				left_q.pop();
				int b = right_q.top();
				right_q.pop();
				left_q.push(b);
				right_q.push(a);
			}
		}
		printf("%d\n", right_q.top());
	}
	return 0;
}