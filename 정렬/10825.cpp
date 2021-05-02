#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N;
vector<pair<pair<int, int>, pair<int, string>>>v;
bool cmp(pair<pair<int, int>, pair<int, string>>a, pair<pair<int, int>, pair<int, string>>b)
{
	if (a.first.first > b.first.first)return true;
	else if (a.first.first < b.first.first)return false;
	else
	{
		if (a.first.second < b.first.second)return true;
		else if (a.first.second > b.first.second)return false;
		else {
			if (a.second.first > b.second.first)return true;
			else if (a.second.first < b.second.first)return false;
			else {
				if (a.second.second < b.second.second)return true;
				else return false;
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		string name; int han, eng, math;
		cin >> name >> han >> eng >> math;
		v.push_back({ {han,eng},{math,name} });
	}
	sort(v.begin(), v.end(), cmp);
	for (pair < pair<int, int>, pair<int, string>>a : v) cout << a.second.second << "\n";
	return 0;
}

