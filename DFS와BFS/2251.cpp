#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
bool visit[201][201][201];
int A, B, C;
int main()
{
	scanf("%d %d %d", &A, &B, &C); ios::sync_with_stdio(false);
	vector<int>v;
	queue<pair<pair<int, int>, int>>q; q.push({ {0,0},C }); visit[0][0][C] = true;
	while (!q.empty()) {
		int curA = q.front().first.first, curB = q.front().first.second, curC = q.front().second; q.pop();
		if (curA == 0)v.emplace_back(curC);
		int nextA = curA + curB;
		if (nextA <= A) {
			if (!visit[nextA][0][curC]) { q.push({ {nextA,0},curC }), visit[nextA][0][curC] = true; }
		}
		else {
			if (!visit[A][nextA - A][curC]) {
				q.push({ {A,nextA - A},curC }), visit[A][nextA - A][curC] = true;
			}
		}
		nextA = curA + curC;
		if (nextA <= A) {
			if (!visit[nextA][curB][0]) {
				q.push({ {nextA,curB},0 }), visit[nextA][curB][0] = true;
			}
		}
		else {
			if (!visit[A][curB][nextA - A]) {
				q.push({ {A,curB},nextA - A }), visit[A][curB][nextA - A] = true;
			}
		}
		int nextB = curA + curB;
		if (nextB <= B) {
			if (!visit[0][nextB][curC]) {
				q.push({ {0,nextB},curC }), visit[0][nextB][curC] = true;
			}
		}
		else {
			if (!visit[nextB - B][B][curC]) {
				q.push({ {nextB - B,B},curC }), visit[nextB - B][B][curC] = true;
			}
		}
		nextB = curB + curC;
		if (nextB <= B) {
			if (!visit[curA][nextB][0]) {
				q.push({ {curA,nextB},0 }), visit[curA][nextB][0] = true;
			}
		}
		else {
			if (!visit[curA][B][nextB - B]) {
				q.push({ {curA, B},nextB - B }), visit[curA][B][nextB - B] = true;
			}
		}
		int nextC = curA + curC;
		if (nextC <= C) {
			if (!visit[0][curB][nextC]) {
				q.push({ {0,curB},nextC }), visit[0][curB][nextC] = true;
			}
		}
		else {
			if (!visit[nextC - C][curB][C]) {
				q.push({ {nextC - C,curB},C }), visit[nextC - C][curB][C] = true;
			}
		}
		nextC = curB + curC;
		if (nextC <= C) {
			if (!visit[curA][0][nextC]) {
				q.push({ {curA,0},nextC }), visit[curA][0][nextC] = true;
			}
		}
		else {
			if (!visit[curA][nextC - C][C]) {
				q.push({ {curA,nextC - C},C }), visit[curA][nextC - C][C] = true;
			}
		}
	}sort(v.begin(), v.end());
	for (int i : v)printf("%d ", i);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);