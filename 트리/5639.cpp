#include<iostream>
#include<map>
using namespace std;
map<int, pair<int, int>>m;
void post(int num)
{
	if (m[num].first != 0)post(m[num].first);
	if (m[num].second != 0)post(m[num].second);
	cout << num << "\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a, root; cin >> a; root = a;
	while (cin >> a)
	{
		int val = root;
		while (1)
		{
			if (a < val)
			{
				if (m[val].first == 0) { m[val].first = a; break; }
				else val = m[val].first;
			}
			else
			{
				if (m[val].second == 0) { m[val].second = a; break; }
				else val = m[val].second;
			}
		}
	}
	post(root);
}