#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int a, b, c; cin >> a >> b; for (int i = 0; i < a; i++) { cin >> c; if (c < b)cout << c << " "; }
	return 0;
}