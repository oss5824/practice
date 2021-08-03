#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int N, dpMax[3], dpMin[3], q, w, e;
int main()
{
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> dpMax[0] >> dpMax[1] >> dpMax[2];
	dpMin[0] = dpMax[0]; dpMin[1] = dpMax[1]; dpMin[2] = dpMax[2];
	for (int i = 1; i < N; i++) {
		cin >> q >> w >> e;
		int a = max(dpMax[0], dpMax[1]) + q;
		int b = max(dpMax[0], max(dpMax[1],dpMax[2])) + w;
		int c = max(dpMax[1], dpMax[2]) + e;
		dpMax[0] = a, dpMax[1] = b, dpMax[2] = c;
		a = min(dpMin[0], dpMin[1]) + q;
		b = min(dpMin[0], min(dpMin[1], dpMin[2])) + w;
		c = min(dpMin[1], dpMin[2]) + e;
		dpMin[0] = a, dpMin[1] = b, dpMin[2] = c;
	}
	printf("%d %d", max(dpMax[0], max(dpMax[1], dpMax[2])), min(dpMin[0], min(dpMin[1], dpMin[2])));
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);