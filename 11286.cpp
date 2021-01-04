#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
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
	priority_queue<int, vector<int>, less<int>>nq;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			if (pq.empty() && nq.empty())printf("0\n");
			else if (pq.empty())
			{
				printf("%d\n", nq.top());
				nq.pop();
			}
			else if (nq.empty())
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
			else
			{
				if (pq.top() < abs(nq.top()))
				{
					printf("%d\n", pq.top());
					pq.pop();
				}
				else if (pq.top() > abs(nq.top()))
				{
					printf("%d\n", nq.top());
					nq.pop();
				}
				else 
				{
					printf("%d\n", nq.top());
					nq.pop();
				}
			}
		}
		else if (v[i] < 0)nq.push(v[i]);
		else if (v[i] > 0)pq.push(v[i]);
	}
	return 0;
}