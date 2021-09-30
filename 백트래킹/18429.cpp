#include<iostream>
#include<algorithm>
using namespace std;
int n, k, arr[8], v[8], cnt;
int main(){
	cin >> n >> k; for (int i = 0; i < n; i++)cin >> v[i], arr[i] = i;
	do {
		bool check = false;
		int sum = 500;
		for (int i = 0; i < n; i++) {
			sum += v[arr[i]] - k;
			if (sum < 500) { check = true; break; }
		}
		if (!check)cnt++;
	} while (next_permutation(arr, arr + n));
	cout << cnt;
}