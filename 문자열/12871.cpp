#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a % b);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s1, s2, res1, res2;
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length(), len = (len1 * len2) / gcd(len1, len2);
	for (int i = 0; i < len / len1; i++)res1 += s1;
	for (int i = 0; i < len / len2; i++)res2 += s2;
	if (res1 == res2)cout << "1";
	else cout << "0";
}