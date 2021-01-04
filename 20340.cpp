#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			if (pq.empty())printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(v[i]);
	}
	return 0;
}