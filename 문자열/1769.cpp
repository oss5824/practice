#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#include<string>
#define INF 1e9
using namespace std;
string s;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> s;
	int len = s.length(), cnt = 0;
	while (len != 1){
		int sum = 0;
		for (int i = 0; i < len; i++) sum += s[i] - '0';
		s = to_string(sum);
		len = s.length();
		cnt++;
	}
	cout << cnt << "\n";
	if (s == "3" || s == "6" || s == "9")cout << "YES";
	else cout << "NO";
	return 0;
}


