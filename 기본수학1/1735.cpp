#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2;
    c1 = a1 * b2 + a2 * b1; c2 = a2 * b2;
    int a = c1, b = c2;
    if (a < b) { int tmp = a; a = b; b = tmp; }
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    cout << c1 / a << " " << c2 / a;
}