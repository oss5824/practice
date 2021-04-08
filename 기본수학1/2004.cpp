#include<iostream>
using namespace std;
int n, m, a, b, check, arr[500001], level[500001];
int search(int num) { if (arr[num] == num)return num; else return arr[num] = search(arr[num]); }
bool merge(int x, int y)
{
	int a = search(x), b = search(y); if (a == b)return true;
	if (level[a] > level[b]) { int tmp = a; a = b; b = tmp; }
	arr[a] = b;
	if (level[a] == level[b])level[b]++;
	return false;
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m; for (int i = 0; i < n; i++) { arr[i] = i; level[i] = 1; }
	for (int i = 1; i <= m; i++) { cin >> a >> b; if (merge(a, b)) { if (check == 0)check = i; } }
	cout << check;
	return 0;
}