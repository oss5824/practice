#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001], level[1000001];
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
bool exist(int a, int b) { if (search(a) == search(b))return true; else return false; }
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { arr[i] = i; level[i] = 1; }
	for (int q = 0; q < m; q++)
	{
		cin >> a >> b >> c;
		if (a == 0)add(b, c); else { if (exist(b, c))cout << "YES\n"; else cout << "NO\n"; }
	}
	return 0;
}




























/*
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[1000001], level[1000001];
int search(int num)
{
	if (arr[num] == num)return num;
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
bool exist(int a, int b)
{
	int x = search(a), y = search(b);
	if (x == y)return true; else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { arr[i] = i; level[i] = 1; }
	for (int q = 0; q < m; q++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)add(b, c);
		else if (a == 1) { if (exist(b, c))cout << "YES\n"; else cout << "NO\n"; }
	}
	return 0;
}

*/