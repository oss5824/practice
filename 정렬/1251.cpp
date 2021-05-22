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
#define INF 1e9
using namespace std;
vector<int>v;
string result;
int len;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	string s;
	cin >> s; len = s.length();
	for (int i = 1; i <= len-2; i++)
	{
		for (int j = 1; i + j <= len - 1; j++)
		{
			for (int k = 1; i + j + k <= len; k++)
			{
				if (i + j + k != len)continue;
				string s1 = s.substr(0, i);
				string s2 = s.substr(i , j);
				string s3 = s.substr(i + j, k);
				reverse(s1.begin(), s1.end());
				reverse(s2.begin(), s2.end());
				reverse(s3.begin(), s3.end());
				string res = s1 + s2 + s3;
				 if (result==""||result > res)result = res;
			}
		}
	}
	cout << result;
	return 0;
}