#include<iostream>
#include<queue>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>>q;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int n; cin >> n;
			if (q.size() >= N) {
				if (q.top() > n)continue;
				else { q.pop(); q.push(n); }
			}
			else q.push(n);
		}
	cout << q.top();
	return 0;
}

