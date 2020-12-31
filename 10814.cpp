#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	vector<pair<unsigned short, char*>> v(n);
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		char* str = new char[210];
		cin.getline(str, 210);
		char* token = strtok(str, " ");
		v[i].first = atoi(token);
		v[i].second = strtok(NULL, "\n");
	}
	stable_sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)printf("%d %s\n", v[i].first, v[i].second);
	return 0;
}