#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n = 9, m = 9, arr[10]; vector<int>v; bool check = false;
	for (int i = 1; i < 10; i++)cin >> arr[i];
	for (int i = 1; i <= 8; i++){
		for (int j = i + 1; j <= 9; j++){
			int sum = 0;
			for (int k = 1; k <= 9; k++)if (i != k && j != k)sum += arr[k];
			if (sum == 100) { for (int k = 1; k <= 9; k++)if (i != k && j != k)v.push_back(arr[k]); check = true; break; }
		}
		if (check)break;
	}
	sort(v.begin(), v.end()); for (int i : v)cout << i << "\n";
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
