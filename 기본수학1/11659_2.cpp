#include<iostream>
using namespace std;
int arr[100001];
int main(){
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, b; cin >> n >> m; for (int i = 1; i <= n; i++) { cin >> arr[i]; arr[i] += arr[i - 1]; }
	while (m--) { cin >> a >> b; cout << arr[b] - arr[a - 1] << "\n"; }
	return 0;
}