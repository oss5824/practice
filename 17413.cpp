#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	string s, result;
	getline(cin, s);
	int start = 0, len = s.length();
	while (start < len)
	{
		if (s.find('<', start) == string::npos && s.find(' ', start) == string::npos) {
			string revs = s.substr(start, len - start);
			reverse(revs.begin(), revs.end());
			result.append(revs);
			break;
		}
		if (s[start] == '<') {
			int index = s.find('>', start);
			string token = s.substr(start, index - start + 1);
			result.append(token);
			start = index + 1;
		}
		else {
			int index1 = s.find('<', start), index2 = s.find(' ', start);
			if (index1 < 0) {
				string revs = s.substr(start, index2 - start);
				reverse(revs.begin(), revs.end());
				result.append(revs + " ");
				start = index2 + 1;
			}
			else if (index2 < 0) {
				string revs = s.substr(start, index1 - start);
				reverse(revs.begin(), revs.end());
				result.append(revs);
				start = index1;
			}
			else if (index2 < index1) {
				string revs = s.substr(start, index2 - start);
				reverse(revs.begin(), revs.end());
				result.append(revs + " ");
				start = index2 + 1;
			}
			else if (index1 < index2) {
				string revs = s.substr(start, index1 - start);
				reverse(revs.begin(), revs.end());
				result.append(revs);
				start = index1;
			}
		}
	}cout << result;
	return 0;
}

