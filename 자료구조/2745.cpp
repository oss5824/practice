#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int N;
	while (cin >> N) {
		int a[100000]; for (int i = 0; i < N; i++)cin >> a[i];
		vector<int>v; v.push_back(a[0]);
		for (int i = 1; i < N; i++) {
			if (v.back() < a[i])v.push_back(a[i]);
			else v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
		}cout << v.size() << "\n";
	}
}
