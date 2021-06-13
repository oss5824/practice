#pragma warning(disable: 4996)
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
#define INF LLONG_MAX
typedef long long ll;
using namespace std;
int N, I, M;
int bitString[10001];
int knowString;
inline int charToInt(char c) {
	int shiftSize = c - 'a';
	int n = 1; n = n << shiftSize;
	return n;
}
int main()
{
	ios::sync_with_stdio(false);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		char s[1002]; scanf("%s", s);
		int len = strlen(s);
		for (int j = 0; j < len; j++){
			bitString[i] = bitString[i] | charToInt(s[j]);
		}
	}
	for (int i = 0; i < 26; i++) knowString = knowString | charToInt(i + 'a');
	
	for (int i = 0; i < M; i++) {
		int cnt = 0, n; char c;
		scanf("%d %c", &n, &c);
		int value = charToInt(c);
		if (n == 1) knowString = knowString & (~value);
		else if (n == 2) knowString = knowString | value;

		for (int i = 0; i < N; i++) {
			if ((knowString & bitString[i]) == bitString[i])cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}


