#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool can(vector<int>v, int start, int end)
{
	if (start >= end)return true;
	else if (v[start] == v[end])return can(v, start + 1, end - 1);
	else return false;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, T;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int start, end;
		cin >> start >> end;
		start--, end--;
		int value = (can(v, start, end)) ? 1 : 0;
		printf("%d\n", value);
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, T;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int start, end;
		cin >> start >> end;
		start--, end--;
		int num = end - start + 1;
		vector<int>vec(num);
		vec.assign(v.begin() + start, v.begin() + end + 1);
		vector<int>revec = vec;
		reverse(revec.begin(), revec.end());
		int res = (vec == revec) ? 1 : 0;
		printf("%d\n", res);
	}
	return 0;
}