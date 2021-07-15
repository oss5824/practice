#include <iostream>
using namespace std;
int N, M, sum;
char s[100][101];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)cin >> s[i];
    for (int j = 0, h = -1; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (s[i][j] == '/' || s[i][j] == '\\') {
                if (h == -1)h = i;
                else { sum += (i - h); h = -1; }
            }
        }
    }
    cout << sum;
}