#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
int N; ll v[5000];
ll befSum = 3e9 + 1;
pair<pair<int, int>, int>res;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> v[i]; sort(v, v + N);
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int s = j + 1, e = N - 1;
			while (s <= e) {
				int m = (s + e) / 2;
				ll sum = v[i] + v[j] + v[m];
				if (abs(sum) < befSum) { befSum = abs(sum); res = { {i,j},m }; }
				if (sum > 0)e = m - 1; else if (sum < 0)s = m + 1;
				else { cout << v[i] << " " << v[j] << " " << v[m]; return 0; }
			}
		}
	}
	cout << v[res.first.first] << " " << v[res.first.second] << " " << v[res.second];
	return 0;
}
