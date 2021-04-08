#include <iostream>
#include <algorithm>
using namespace std;
int arr[201], level[201], result[1001];
int search(int num)
{
	if (num == arr[num])return num;
	else return arr[num] = search(arr[num]);
}
void add(int a, int b)
{
	int x = search(a), y = search(b);
	if (x == y)return;
	if (level[x] > level[y]) { int tmp = x; x = y; y = tmp; }
	arr[x] = y;
	if (level[x] == level[y])level[y]++;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { arr[i] = i; level[i] = 1; }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> a;
			if (i < j && a == 1)add(i, j);
		}
	for (int i = 1; i <= m; i++)cin >> result[i];
	int value = search(result[1]);
	bool judge = true;
	for (int i = 2; i <= m; i++)if (value != search(result[i])) { judge = false; break; }
	if (judge)cout << "YES\n"; else cout << "NO\n";
	return 0;
}