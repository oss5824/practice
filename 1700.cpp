#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>arr;
vector<int>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n, m, a, cnt = 0; cin >> n >> m; for (int i = 0; i < m; i++) { cin >> a; arr.push_back(a); }
	for (int i = 0; i < m; i++){
		if (find(v.begin(), v.end(), arr[i]) != v.end())continue;
		if (v.size() == n)
		{
			int idxMax = 0, value = v[n - 1]; cnt++;
			for (int val : v)
			{
				int idx = find(arr.begin() + i + 1, arr.end(), val) - (arr.begin() + i + 1);
				if (idxMax < idx) { idxMax = idx; value = val; }
			}
			int idx = find(v.begin(), v.end(), value) - v.begin();
			v[idx] = arr[i];
		}
		else v.push_back(arr[i]);
	}cout << cnt;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);