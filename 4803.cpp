#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> arr;
int result, zero;
vector<int>*v;
bool bfs(int num)
{
	queue<int>q;
	q.push(num);
	arr[num] = result;
	int all = v[num].size(), cnt = 0;
	while (!q.empty())
	{
		int cur = q.front(), len = v[cur].size(); 
		q.pop();
		for (int i = 0; i < len; i++)
		{
			int next = v[cur][i];
			if (arr[next] == 0) { q.push(next); arr[next] = result; cnt++; all += v[next].size(); }
		}
	}
	if (cnt < (all / 2))return false;
	else return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int j = 1;; j++)
	{
		int a, b, c, d;
		cin >> a >> b;
		if (a == 0 && b == 0)break;
		arr.assign(a + 1, 0); v = new vector<int>[a + 1];
		result = 1, zero = 0;
		for (int i = 0; i < b; i++) { cin >> c >> d; v[c].push_back(d); v[d].push_back(c); }
		for (int i = 1; i <= a; i++)if (arr[i] == 0)if (bfs(i)) result++;
		for (int i = 1; i <= a; i++)if (arr[i] == 0)zero++;
		if (result == 1 && zero == 0)cout << "Case " << j << ": No trees." << "\n";
		else if (result == 2 && zero == 0)cout << "Case " << j << ": There is one tree." << "\n";
		else cout << "Case " << j << ": A forest of " << result - 1 + zero << " trees." << "\n";
	}
	return 0;
}
