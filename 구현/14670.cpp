#include<iostream>
#include<vector>
using namespace std;
int arr[101];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); fill(arr, arr + 101, -1);
	int n, m, a, b; cin >> n; while (n--) { cin >> a >> b; arr[a] = b; }cin >> m;
	while (m--){
		cin >> a; vector<int>v;
		for (int i = 0; i < a; i++) { cin >> b; if (arr[b] != -1)v.push_back(arr[b]); }
		if (a != v.size())cout << "YOU DIED\n";
		else { for (int i : v)cout << i << " "; cout << "\n"; }
	}
	return 0;
}