#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int arr[1001];
int M[1001];
int n, m, vmin = 1000000;
void bfs()
{
	queue<int>q;
	q.push(n);
	while (!(q.empty()))
	{
		int pos = q.front();
		q.pop();
		arr[pos] = 1;
		int move[3] = { 1,-1,pos };
		for (int k = 0; k < 3; k++)
		{
			if (pos + move[k] < 0 || pos + move[k] >1000)continue;
			if (arr[pos + move[k]] == 0)
			{
				arr[pos + move[k]] = 1;
				M[pos + move[k]] = M[pos] + 1;
				printf("pos : %d, pos+move : %d, M[pos+move] : %d\n", pos, pos + move[k], 
					M[pos + move[k]]);
				if (pos + move[k] == m)vmin = min(vmin, M[pos + move[k]]);
				q.push(pos + move[k]);
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(arr, 0, sizeof(arr));
	memset(M, 0, sizeof(M));
	bfs();
	printf("%d", vmin);
	return 0;
}