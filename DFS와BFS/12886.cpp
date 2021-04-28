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
int a, b, c;
map<pair<pair<int, int>, int>, int>m;
pair<int,int> cal(int x,int y)
{
	if (x == y)return { x,y };
	return { x + x,y - x };
}
void bfs()
{
	queue<pair<pair<int, int>, int>>q; q.push({ { a,b } ,c });
	m[{ {a, b, }, c}] = 1;

	while (!q.empty()) {
		int curA = q.front().first.first, curB = q.front().first.second, curC = q.front().second;
		vector<int>v; v.push_back(curA); v.push_back(curB); v.push_back(curC);
		q.pop();
		if (curA == curB && curB == curC) { cout << "1"; return; }
		sort(v.begin(), v.end());
		curA = v[0]; curB = v[1]; curC = v[2];
		pair<int, int>res = cal(curA, curB);

		if (m[{ {res.first, res.second}, curC}] == 0) {
			q.push({ {res.first,res.second},curC });
			m[{ {res.first, res.second}, curC}] = 1;
		}

		res = cal(curB, curC);

		if (m[{ {curA, res.first}, res.second}] == 0) {
			q.push({ {curA,res.first},res.second });
			m[{ {curA, res.first}, res.second}] = 1;
		}

		res = cal(curA, curC);
		if (m[{ {res.first, curB}, res.second}] == 0) {
			q.push({ {res.first,curB},res.second });
			m[{ {res.first, curB}, res.second}] = 1;
		}
	}
	cout << "0";
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	bfs();
	return 0;
}