#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	double N, M, K; cin >> N >> M >> K;
	while (K != 0) {
		if (N / M > (double)2)N--;
		else M--;
		K--;
	}
	N / M >= 2 ? cout << M : cout << ((int)N / 2);
	return 0;
}

