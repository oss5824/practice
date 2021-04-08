#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[100001];
int M[100001];
int n, l, vmin = 0;
void bfs()
{
	queue<int>q;
	q.push(n);
	bool end = false;
	while (!(q.empty()))
	{
		int pos = q.front();
		q.pop();
		if (pos == l)break;
		arr[pos] = 1;
		int move[3] = { 1,-1,pos };
		for (int k = 0; k < 3; k++)
		{
			if (pos + move[k] < 0 || pos + move[k] >100000)continue;
			if (arr[pos + move[k]] == 0)
			{
				arr[pos + move[k]] = 1;
				M[pos + move[k]] = M[pos] + 1;
				q.push(pos + move[k]);
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> l;
	memset(arr, 0, sizeof(arr));
	memset(M, 0, sizeof(M));
	bfs();
	printf("%d", M[l]);
	return 0;
}
