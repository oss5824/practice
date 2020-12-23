#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int count = 0, position = 0, importance = 0, val = 0, index = 0, result = 0;
		queue<int>value;
		cin >> count >> position;
		for (int j = 0; j < count; j++)
		{
			cin >> importance;
			value.push(importance);
			val = (j == position) ? importance : val;
		}
		while (!(value.empty()))
		{
			int max = 0;
			for (int j = 0; j < value.size(); j++)
			{
				int tmp = value.front();
				max = MAX(max, tmp);
				value.pop();
				value.push(tmp);
			}
			if ((value.front() == max && max != val) ||
				(value.front() == val && max == val && position != 0))
			{
				value.pop();
				position--;
				result++;
			}
			else if (value.front() == val && position == 0 && max == val)
			{
				result++;
				break;
			}
			else if (position == 0)
			{
				position = value.size() - 1;
				value.push(value.front());
				value.pop();
			}
			else
			{
				value.push(value.front());
				value.pop();
				position--;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
//	cin.tie(NULL);
//ios::sync_with_stdio(false);
