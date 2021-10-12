#include <iostream>
#include <string>
using namespace std;
int N, K, blue, red, green;
string s;
void getColor(int idx){
    if (s[idx] == 'B')blue++; else if (s[idx] == 'G')green++; else red++;
}
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> K >> s;
    while (K--) {
        string tmp = s;
        for (int i = 0; i < N; i++) {
            int left = (i == 0) ? N - 1 : i - 1, mid = i, right = (i == N - 1) ? 0 : i + 1;
            if ((s[left] == s[mid] && s[mid] == s[right]) || (s[left] != s[mid] && s[mid] != s[right] &&
                s[left] != s[right]))tmp[mid] = 'B';
            else {
                blue = 0; red = 0; green = 0;
                getColor(left); getColor(mid); getColor(right);
                if ((red == 2 && green == 1) || (green == 2 && blue == 1) || (blue == 2 && red == 1))tmp[mid] = 'R';
                else tmp[mid] = 'G';
            }
        }s = tmp;
    }blue = 0; red = 0; green = 0;
    for (int i = 0; i < N; i++)getColor(i);
    cout << red << " " << green << " " << blue;
}