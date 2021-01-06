#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	queue<char>q;
	vector <short>b(n + 1, 0);
	stack <int>s;
	vector <int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	int start = 0;
	bool no = true;
	while (v[0] != start)
	{
		start++;
		q.push('+');
		s.push(start);
		b[start] = true;
	}
	q.push('-');
	s.pop();
	b[start--] = 2;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] < v[i])
		{
			while (v[i] != start)
			{
				start++;
				if (b[start] != 2)
				{
					q.push('+');
					s.push(start);
					b[start] = 1;
				}
			}
			if (b[start] == 2)no = false;
		}
		else if (v[i - 1] > v[i])
		{
			while (v[i] != start)
			{
				if (b[start] != 2)
				{
					q.push('-');
					s.pop();
					b[start] = 2;
				}
				start--;
			}
		}
		if (no == false)break;
		q.push('-');
		s.pop();
		b[start--] = 2;
	}
	if (no == false)printf("NO");
	else
	{
		while (!(q.empty()))
		{
			printf("%c\n", q.front());
			q.pop();
		}
	}
	return 0;
}