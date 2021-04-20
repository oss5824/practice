#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, arr[100001], result;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> arr[i]; }
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		int sum = arr[i] * (N - i);
		result = max(result, sum);
	}cout << result;
	return 0;
}


