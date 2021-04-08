#include<iostream>
using namespace std;
int M[10];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s; cin >> s; int len = s.length(), result = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '6' || s[i] == '9') { if (M[6] < M[9])M[6]++; else M[9]++; }
		else M[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++)result = (result < M[i]) ? M[i] : result;
	cout << result;
	return 0;
}

