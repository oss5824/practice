#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
typedef unsigned long long ull;
using namespace std;
string s1, s2;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length(), len = max(len1, len2);
	if (len1 < len2) { for (int i = len1; i < len2; i++)s1 = '0' + s1; }
	else if (len1 > len2) { for (int i = len2; i < len1; i++)s2 = '0' + s2; }
	int up = 0;
	string result;
	for (int i = len - 1; i >= 0; i--) {
		int a = s1[i] - '0', b = s2[i] - '0';
		int sum = a + b + up;
		if (sum >= 10) { up = 1; sum -= 10; }
		else up = 0;
		result.push_back(sum + '0');
	}
	if (up == 1)result.push_back('1');
	len = result.length();
	for (int i = len - 1; i >= 0; i--)cout << result[i];

	return 0;
}

