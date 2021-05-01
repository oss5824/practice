#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, arr1[1000000], arr2[1000000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> arr1[i]; for (int i = 0; i < M; i++)cin >> arr2[i];
	int s1 = 0, s2 = 0;
	while (s1 < N || s2 < M) {
		if (s1 >= N) { cout << arr2[s2++] << " "; }
		else if (s2 >= M) { cout << arr1[s1++] << " "; }
		else if (arr1[s1] < arr2[s2]) { cout << arr1[s1++] << " "; }
		else if (arr1[s1] > arr2[s2]) { cout << arr2[s2++] << " "; }
		else if (arr1[s1] == arr2[s2]) { cout << arr1[s1++] << " "; }
	}
	return 0;
}

