#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n;
	while (n--){
		string s; cin >> s; int len = s.length();
		pair<int, int>p = { 0,0 }; char d = 'U';
		int max_x = 0, min_x = 0;
		int max_y = 0, min_y = 0;
		for (int i = 0; i < len; i++){
			if (s[i] == 'F') {
				if (d == 'U') { p.second = p.second + 1; if (max_y < p.second)max_y = p.second; }
				else if (d == 'D') { p.second = p.second - 1; if (min_y > p.second)min_y = p.second; }
				else if (d == 'L') { p.first = p.first - 1; if (min_x > p.first)min_x = p.first; }
				else if (d == 'R') { p.first = p.first + 1; if (max_x < p.first)max_x = p.first; }
			}else if (s[i] == 'B') {
				if (d == 'U') { p.second = p.second - 1; if (min_y > p.second)min_y = p.second; }
				else if (d == 'D') { p.second = p.second + 1; if (max_y < p.second)max_y = p.second; }
				else if (d == 'L') { p.first = p.first + 1; if (max_x < p.first)max_x = p.first; }
				else if (d == 'R') { p.first = p.first - 1; if (min_x > p.first)min_x = p.first; }
			}
			else if (s[i] == 'L') {
				if (d == 'U')d = 'L';
				else if (d == 'D')d = 'R';
				else if (d == 'L')d = 'D';
				else if (d == 'R')d = 'U';
			}
			else if (s[i] == 'R') {
				if (d == 'U')d = 'R';
				else if (d == 'D')d = 'L';
				else if (d == 'L')d = 'U';
				else if (d == 'R')d = 'D';
			}
		}
		int width = (max_x > min_x) ? (max_x - min_x) : (min_x - max_x);
		int height = (max_y > min_y) ? (max_y - min_y) : (min_y - max_y);
		cout << width * height << "\n";
	}
	return 0;
}


