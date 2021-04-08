#include <iostream>
#include <string>
#include <bitset>
using namespace std;
string s; int n;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; cin.ignore();
	getline(cin, s); int len = s.length(), line_len = len / 5;
	for (int i = 0; i < line_len; i++)
	{
		while (s[i] == '.')i++;
		if (i >= line_len)break;
		int idx = 0; int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int j = i; idx < 3; j++, idx++) {
			int jump = j;
			if (j >= line_len) { cnt1 = 5; cnt2 = 0; break; }
			for (int k = 0; k < 5; k++, jump += line_len){
				if (s[jump] == '#' && idx == 0)cnt1++;
				if (s[jump] == '#' && idx == 1)cnt2++;
				if (s[jump] == '#' && idx == 2)cnt3++;
			}
		}
		if (cnt1 == 5 && cnt2 == 0)cout << "1";
		else if (cnt1 == 5 && cnt2 == 2) { cout << "0"; i = i + 2; }
		else if (cnt1 == 3 && cnt2 == 3) { cout << "3"; i = i + 2; }
		else if (cnt1 == 3 && cnt2 == 1) { cout << "4"; i = i + 2; }
		else if (cnt1 == 5 && cnt2 == 3 && cnt3 == 5) { cout << "8"; i = i + 2; }
		else if (cnt1 == 5 && cnt2 == 3) { cout << "6"; i = i + 2; }
		else if (cnt1 == 1 && cnt2 == 1) { cout << "7"; i = i + 2; }
		else if (cnt1 == 4 && cnt2 == 3 && cnt3 == 5) { cout << "9"; i = i + 2; }
		else{
			if (s[i + line_len] == '.')cout << "2";
			else cout << "5";
			i = i + 2;
		}
	}
	return 0;
}


