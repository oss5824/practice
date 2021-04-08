#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	getline(cin, s); int index = 0, start = 0; string res = "";
	while (s[start] != ' '){
		res += s[start];
		start++;
	}start++;
	while ((index = s.find(',', start)) != string::npos){
		string s1 = "", s2 = ""; start = index + 1; index--;
		while (!isalpha(s[index])){
			if (s[index] == ']') { index--; s1 += "[]"; }
			else { s1 += s[index]; }
			index--;
		}
		while (isalpha(s[index])) { s2 = s[index] + s2; index--; }
		s1 = s1 + " " + s2 + ";";
		cout << res + s1 << "\n";
	}
	index = s.find(';', start); string s1 = ""; index--; string s2 = "";
	while (!isalpha(s[index])) {
		if (s[index] == ']') { index--; s1 += "[]"; }
		else { s1 += s[index]; }
		index--;
	}
	while (isalpha(s[index])) { s2 = s[index] + s2; index--; }
	s1 = s1 + " " + s2 + ";";
	cout << res + s1 << "\n";
	return 0;
}


