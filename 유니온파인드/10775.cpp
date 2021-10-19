#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int arr[100001];
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int p, g, r = 0; cin >> p >> g;
	for (int i = 1; i <= p; i++)arr[i] = i;
	for (int i = 1; i <= g; i++) {
		cin >> p;
		while (arr[p] != p) { arr[p] = arr[arr[p]]; p = arr[p]; }
		if (p == 0)break; arr[p]--; r++;
	}cout << r;
}
//