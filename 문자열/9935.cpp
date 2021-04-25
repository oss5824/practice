#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s, explosion, result;
	cin >> s >> explosion;
	int index = 0, all_len = s.length(), len = explosion.length();
	for (int i = 0; i < all_len; i++) {
		result.push_back(s[i]);
		if (result.size() < len)continue;
		bool check = false;
		int idx = result.size() - 1;
		for (int j = len - 1; j >= 0; j--)if (explosion[j] != result[idx--]) { check = true; break; }
		if (!check) {
			result.erase(idx + 1, len);
		}
	}result.size() == 0 ? cout << "FRULA" : cout << result << "\n";
	return 0;
}