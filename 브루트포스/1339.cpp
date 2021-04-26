#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 1000000000
using namespace std;
int N;
pair<int, char>arr[26];
string str[20];
map<char, int>m;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s; str[i] = s;
		int len = s.size();
		for (int j = len - 1; j >= 0; j--) {
			int ten = pow(10, len - j - 1);
			arr[s[j] - 'A'].first += ten;
			arr[s[j] - 'A'].second = s[j];
		}
	}
	sort(arr, arr + 26, greater<pair<int, char>>());
	int start = 9, sum = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i].first == 0)break;
		m[arr[i].second] = start--;
	}
	for (int i = 0; i < N; i++)
	{
		int len = str[i].length(), value = 0;
		for (int j = len - 1; j >= 0; j--) {
			int ten = pow(10, len - j - 1);
			value += ten * m[str[i][j]];
		}
		sum += value;
	}
	cout << sum;
	return 0;
}