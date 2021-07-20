#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
int N, T, arr[500001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> T;
	for (int i = 1; i <= T; i++)cin >> arr[i];
	cin.ignore();
	deque<string>dq;
	map<int, int>dummy;
	map<int, string>hasOper;
	for (int i = 1; i <= T; i++) {
		string s; getline(cin, s);
		dq.push_back(s);
	}
	for (int i = 1; i <= T; i++) {
		int order = arr[i];
		if (hasOper[order] != "") {
			string s = hasOper[order], tmp;
			istringstream iss(s); getline(iss, tmp, ' ');
			int id = stoi(tmp); getline(iss, tmp, ' ');
			getline(iss, tmp, ' ');
			int num = stoi(tmp);
			if (dummy[num] == 0) { dummy[num] = order; cout << id << "\n"; }
			else { cout << id << "\n"; continue; }
			hasOper[order] = "";
		}
		else {
			string s = dq.front(), tmp;
			istringstream iss(s); getline(iss, tmp, ' ');
			int id = stoi(tmp); getline(iss, tmp, ' ');
			if (tmp == "next") { cout << id << "\n"; dq.pop_front(); continue; }
			else {
				if (tmp == "acquire") {
					//0이면 있다는말
					getline(iss, tmp, ' ');
					int num = stoi(tmp);
					if (dummy[num] == 0) { dummy[num] = order; cout << id << "\n"; }
					else {
						cout << id << "\n"; hasOper[order] = dq.front();
					}
				}
				else {
					getline(iss, tmp, ' ');
					int num = stoi(tmp);
					cout << id << "\n";
					dummy[num] = 0;
				}
				dq.pop_front();
			}
		}
	}
	return 0;
}