#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
int N, C;
vector<string> vs;
vector<string>result;
vector<int>v;
map<int, pair<int, int>>m;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a;
		for (int j = 0; j < a; j++) { cin >> b; m[b] = { i ,j }; }
	}
	cin.ignore();
	for (int i = 1; i <= C; i++) {
		v.push_back(i);
		string s; getline(cin, s); vs.push_back(s);
	}
	do {
		string str = ""; bool check = true;
		int idx[11]; memset(idx, 0, sizeof(idx));
		bool fin = false;
		vector<string>vec;
		for (int i : v) {
			if (m[i].second == idx[m[i].first]) { vec.push_back(vs[i - 1]); idx[m[i].first]++; }
			else { fin = true; break; }
		}
		if (fin)continue;
		for (string tmp : vec) {
			string command;
			istringstream iss(tmp);
			while (getline(iss, command, ',')) {
				if (command.substr(0, 3) == "ADD") {
					str += command.back();
				}
				else {
					int pos = stoi(command.substr(4));
					if (pos >= str.length() || pos < 0) { check = false; break; }
					else str.erase(pos, 1);
				}
			}
			if (!check)break;
		}
		if (!check)result.push_back("ERROR");
		else if (str.empty())result.push_back("EMPTY");
		else result.push_back(str);
	} while (next_permutation(v.begin(), v.end()));
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (string p : result)cout << p << "\n";
	return 0;
}