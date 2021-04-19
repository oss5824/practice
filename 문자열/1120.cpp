#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int result = INF;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s1, s2; cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length();
	int len = len2 - len1;
	for (int i = 0; i <= len; i++)
	{
		int cnt = 0;
		for (int j = 0; j < len1; j++)if (s1[j] != s2[j + i])cnt++;
		result = min(result, cnt);
	}cout << result;
	return 0;
}

