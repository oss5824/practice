#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<limits.h>
#define INF 987654321
using namespace std;
int N;
double arr[10000], M[10000], result;
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	M[0] = arr[0];
	for (int i = 1; i < N; i++) {
		double sum = M[i - 1] * arr[i];
		if (sum < arr[i])M[i] = arr[i];
		else M[i] = sum;
	}
	for (int i = 0; i < N; i++) result = max(result, M[i]);
	printf("%.3f", result);
	return 0;
}


