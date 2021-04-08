#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int A, B;
int M[100001], arr[100001];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B;
	if (A == B) { printf("%d\n%d", 0, A); return 0; }
	queue<int>q;
	stack<int>s;
	q.push(A);
	M[A] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		if (cur == B)break;
		q.pop();
		arr[cur] = 1;
		int move[3] = { -1,1,cur };
		for (int i = 0; i < 3; i++)
		{
			if (cur + move[i] < 0 || cur + move[i] >100000)continue;
			if (arr[cur + move[i]] == 0)
			{
				M[cur + move[i]] = M[cur] + 1;
				arr[cur + move[i]] = 1;
				q.push(cur + move[i]);
			}
		}
	}
	int value = M[B], index = B;
	printf("%d\n%d ", value--, A);
	while (value != 0)
	{
		if (M[index - 1] == value) { value--; index--; s.push(index); }
		else if (M[index + 1] == value) { value--; index++; s.push(index); }
		else if (index % 2 == 0 && M[index / 2] == value) { value--; index /= 2; s.push(index); }
	}
	while (!s.empty()) { printf("%d ", s.top()); s.pop(); }
	printf("%d", B);
	return 0;
}