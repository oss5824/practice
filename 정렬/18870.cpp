#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, arr[1000000], arr2[1000000];
map<int, int>m;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> arr[i]; arr2[i] = arr[i]; }

	sort(arr2, arr2 + N);
	int min_value = INT_MIN;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (min_value < arr2[i]) {
			m[arr2[i]] = cnt;
			min_value = arr2[i]; cnt++;
		}
	}
	for (int i = 0; i < N; i++)cout << m[arr[i]] << " ";
	return 0;
}


