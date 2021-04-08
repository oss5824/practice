#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
int arr[12], op[5], len, n, M = INT_MIN, m = INT_MAX;
char c[5] = { '+','-','*','%' };
vector<char>v;
vector<char>res;
vector<bool>visit;
void dfs()
{
	if (res.size() == n - 1){
		int sum = arr[0];
		for (int i = 0; i < n - 1; i++){
			if (res[i] == '+') sum += arr[i + 1];
			else if (res[i] == '-') sum -= arr[i + 1];
			else if (res[i] == '*') sum *= arr[i + 1];
			else if (res[i] == '%') sum /= arr[i + 1];
		}
		M = max(M, sum); m = min(m, sum);
		return;
	}
	for (int i = 0; i < len; i++){
		if (!visit[i]) {
			visit[i] = true;
			res.push_back(v[i]);
			dfs();
			res.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) { cin >> op[i]; for (int j = 0; j < op[i]; j++)v.push_back(c[i]); }
	len = v.size(); visit.assign(len, false); dfs();
	cout << M << "\n" << m;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
