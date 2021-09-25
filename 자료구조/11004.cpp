#include <iostream>
#include <queue>
using namespace std;
int N, K, a;
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K; priority_queue<int>q;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (q.size() < K)q.push(a);
		else if (q.top() > a)q.pop(), q.push(a);
	}cout << q.top();
}