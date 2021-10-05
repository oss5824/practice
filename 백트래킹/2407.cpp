#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string n, m, Map[101][101];

string addString(string a, string b)
{
	string result;
	while (a.length() != b.length()) {
		if (a.length() > b.length())b = '0' + b;
		else a = '0' + a;
	}
	int len = a.length(), up = 0;
	for (int i = len - 1; i >= 0; i--) {
		int x = a[i] - '0', y = b[i] - '0';
		int z = x + y + up;
		if (z >= 10)up = 1, result.push_back((z - 10) + '0');
		else up = 0, result.push_back(z + '0');
	}if (up == 1)result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}
string solve(string a, string b)
{
	if (a == b || b == "0")return "1";
	string &ret = Map[stoi(a)][stoi(b)];
	if (ret != "")return ret;
	ret = addString(solve(to_string(stoi(a)-1), to_string(stoi(b) - 1)), 
		solve(to_string(stoi(a) - 1), to_string(stoi(b))));
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m; cout << solve(n, m);
	return 0;
}
