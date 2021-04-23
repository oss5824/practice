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
bool not_prime[1003002];
bool check(int num)
{
	string s = to_string(num);
	string rev = s;
	reverse(rev.begin(), rev.end());
	if (rev == s)return true;
	else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; not_prime[1] = true;
	for (int i = 2; i <= 1003001; i++)
	{
		if (not_prime[i])continue;
		for (int j = i + i; j <= 1003001; j = j + i)not_prime[j] = true;
	}
	for (int i = N;; i++)if (!not_prime[i] && check(i)) { cout << i; break; }
	return 0;
}


