#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, S, res = 200000;
	cin >> N >> S;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)cin >> arr[i];
	int s = 0, e = 0, sum = 0;
	while (1)
	{
		if (sum >= S)
		{
			res = min(res, e - s);
			sum -= arr[s++];
		}
		else if (e == N)break;
		else sum += arr[e++];
	}
	res = (res == 200000) ? 0 : res;
	printf("%d", res);
	return 0;
}
