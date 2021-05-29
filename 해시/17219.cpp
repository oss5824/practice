#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M;
map<string, string>m;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string address, password;
		cin >> address >> password;
		m[address] = password;
	}
	for (int i = 0; i < M; i++) {
		string address; cin >> address;
		cout << m[address] << "\n";
	}
	return 0;
}