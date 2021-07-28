#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<queue>
#define R 1000000007
typedef long long ll;
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int T, N; cin >> T;
	while (T--) {
		cin >> N; ll a, sum = 1; priority_queue<ll, vector<ll>, greater<ll>>q;
		for (int i = 0; i < N; i++) { cin >> a; q.push(a); }
		while (--N) {
			ll a = q.top(); q.pop(); ll b = q.top(); q.pop();
			sum = (sum * ((a * b) % R)) % R;
			q.push(a * b);
		}cout << sum << "\n";
	}
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);