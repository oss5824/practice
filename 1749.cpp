#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<string>
#define INF 987654321
typedef unsigned long long ull;
using namespace std;
ull N;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s; cin >> s; int len = s.length(); ull sum = 0;
	string nine = "";
	for (int i = 1; i < len; i++)
	{
		ull up = pow(10, i), down = pow(10, i - 1);
		ull diff = up - down;
		sum += diff * i;
	}
	ull ten = pow(10, len - 1);
	sum = sum + (stoi(s) - ten + 1) * (len);
	cout << sum;
	return 0;
}

