#include<iostream>
#include<string>
using namespace std;
int n;
char c;
bool check(int num)
{
	string s = to_string(num);
	if (s.find(c) == string::npos)return true;
	else return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> c; int start = 1;
	for (int i = 1; i <= n; i++, start++) { while (!check(start))start++; }
	cout << start - 1;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);