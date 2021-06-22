#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define INF 1e9
using namespace std;
int N, K;
vector<int>positivePos, negativePos;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	int a, max_distance = 0; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a; if (a > 0)positivePos.push_back(a); else negativePos.push_back(a * -1);
		max_distance = max(max_distance, abs(a));
	}
	sort(negativePos.begin(), negativePos.end());
	sort(positivePos.begin(), positivePos.end());

	int negaLen = negativePos.size(), posLen = positivePos.size(), distance = 0;

	for (int i = posLen - 1; i >= 0; i = i - K) distance += 2 * positivePos[i];
	for (int i = negaLen - 1; i >= 0; i = i - K)distance += 2 * negativePos[i];

	cout << distance - max_distance;

;	return 0;
}



/*
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, K;
priority_queue<int, vector<int>, greater<int>>pq;
priority_queue<int, vector<int>, less<int>>nq;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	int a; cin >> N >> K;
	for (int i = 0; i < N; i++) { cin >> a; if (a > 0)pq.push(a); else nq.push(a); }
	int distance = 0, count = 0;
	while (count == N) {
		for (int i = 0; i < K; i++) {
			if (pq.empty() && nq.empty())break;
			else if (pq.empty()) {

			}
			else if (nq.empty()) {

			}
			else {

			}
		}
	}
;	return 0;
}



*/