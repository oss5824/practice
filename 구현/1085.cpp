#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int x, y, w, h, a, b, c, d; cin >> x >> y >> w >> h;
	a = abs(x - w), b = abs(y - h); c = abs(x - 0), d = abs(y - 0);
	cout << min(min(a, b), min(c, d));
	return 0;
}