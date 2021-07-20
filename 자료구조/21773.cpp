#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int T, N, a, b, c;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T >> N;
	priority_queue<pair<pair<int, int>, int>>q;
	for (int i = 0; i < N; i++) { cin >> a >> b >> c; q.push({ {c,-a},b }); }

	while (T--) {
		if (q.empty())break;
		int id = -q.top().first.second, order = q.top().first.first-1, time = q.top().second - 1; q.pop();
		cout << id << "\n";
		if (time != 0)q.push({ {order,-id},time });
	}
	return 0;
}