#include <iostream>
#include <string>
#include <bitset>
using namespace std;
string s; int n;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n; cin.ignore();
	while (n--)
	{
		getline(cin, s); int index = 0, start = 0;
		index = s.find(' ', start); bool check = false;
		string val = s.substr(start, index); start = index + 1;
		string res = "";
		if (val == "ADD")res += "00000";
		else if (val == "ADDC") { res += "00001"; check = true; }
		else if (val == "SUB")res += "00010";
		else if (val == "SUBC") { res += "00011"; check = true; }
		else if (val == "MOV")res += "00100";
		else if (val == "MOVC") { res += "00101"; check = true; }
		else if (val == "AND")res += "00110";
		else if (val == "ANDC") { res += "00111"; check = true; }
		else if (val == "OR")res += "01000";
		else if (val == "ORC") { res += "01001"; check = true; }
		else if (val == "NOT")res += "01010";
		else if (val == "MULT")res += "01100";
		else if (val == "MULTC") { res += "01101"; check = true; }
		else if (val == "LSFTL")res += "01110";
		else if (val == "LSFTLC") { res += "01111"; check = true; }
		else if (val == "LSFTR")res += "10000";
		else if (val == "LSFTRC") { res += "10001"; check = true; }
		else if (val == "ASFTR")res += "10010";
		else if (val == "ASFTRC") { res += "10011"; check = true; }
		else if (val == "RL")res += "10100";
		else if (val == "RLC") { res += "10101"; check = true; }
		else if (val == "RR")res += "10110";
		else if (val == "RRC") { res += "10111"; check = true; }
		cout << res << "0";
		index = s.find(' ', start); val = s.substr(start, index - 1);
		int num = stoi(val); bitset<3>bit(num); cout << bit; start = index + 1;
		index = s.find(' ', start); val = s.substr(start, index - 1);
		num = stoi(val); bitset<3>bit1(num); cout << bit1; start = index + 1;
		index = s.find(' ', start); val = s.substr(start, index - 1);
		num = stoi(val);
		if (check == true) { bitset<4>bit2(num); cout << bit2; cout << "\n"; }
		else { bitset<3>bit2(num); cout << bit2; cout << "0\n"; }
	}

	return 0;
}


