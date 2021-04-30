#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, K, result;
int sum;
vector<int>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; v.assign(N, 0);
	int mcnt = 0, pcnt = 0, zcnt = 0;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = N - 1; (i >= 0) && (v[i] > 0); i--)
	{
		if (i != 0) {
			if (v[i - 1] == 1) { sum += v[i]; }
			else if (v[i - 1] > 1) { sum += v[i] * v[i - 1]; i--; }
			else { sum += v[i]; break; }
		}
		else sum += v[i];
	}
	for (int i = 0; (i < N) && (v[i] <= 0); i++)
	{
		if (i != N - 1)
		{
			if (v[i + 1] <= 0) { sum += v[i] * v[i + 1]; i++; }
			else { sum += v[i]; break; }
		}
		else sum += v[i];
	}
	cout << sum;
	return 0;
}

