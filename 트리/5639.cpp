#include <iostream>
#include <map>
using namespace std;
map<int, pair<int, int>>m;
void post(int num)
{
	if (m[num].first)post(m[num].first);
	if (m[num].second)post(m[num].second);
	cout << num << "\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int val, a;
	cin >> val;
	while (cin >> a)
	{
		int root = val;
		while (1)
		{
			if (a < root)
			{
				if (m[root].first != 0)root = m[root].first;
				else { m[root].first = a; break; }
			}
			else
			{
				if (m[root].second != 0)root = m[root].second;
				else { m[root].second = a; break; }
			}
		}
	}
	post(val);
	return 0;
}