#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, len = 1;
	long long res = 0, s;
	cin >> n >> s;
	long long* arr = new long long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		res += arr[i];
	}
	if (res < s)printf("0");
	else
	{
		bool br = false;
		while (len != n)
		{
			for (int i = 0; i < n - len; i++)
			{
				long long result = 0;
				for (int j = i; j < i + len; j++)result += arr[j];
				if (result >= s)br = true;
			}
			if (br)break;
			len++;
		}
		printf("%d", len);
	}
	return 0;
}