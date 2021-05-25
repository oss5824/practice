#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, result;
set<int>s1, s2;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	int a, result = 0;;
	for (int i = 0; i < N; i++) { cin >> a; s1.insert(a); result++; }
	for (int i = 0; i < M; i++)
	{
		cin >> a; 
		if (s1.count(a) == 0) { s2.insert(a); result++; }
		else result--;
	}
	cout << result;
	return 0;
}