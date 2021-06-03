#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, result;
int arr[1000];
vector<int>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (v.back() < arr[i])v.push_back(arr[i]);
		else {
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[idx] = arr[i];
		}
	}
	cout << v.size();
	return 0;
}