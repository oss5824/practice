#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool arr[1000001];
int N;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	vector<int>v;
	for (int i = 2; i * i <= 1000000; i++) {
		for (int j = i + i; j <= 1000000; j += i) { if (arr[j])continue; arr[j] = true; }
	}
	for (int i = 2; i <= 1000000; i++) { if (!arr[i])v.push_back(i); }
	int len = v.size();
	while (1) {
		cin >> N; if (N == 0)break;
		int idx = 0, val = 0; bool check = false;
		while (idx < len) {
			val = N - v[idx]; if (!arr[val]) { check = true; break; }
			idx++;
		}
		if (!check)cout << "Goldbach's conjecture is wrong.\n";
		else cout << N << " = " << v[idx] << " + " << val << "\n";
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);