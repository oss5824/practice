#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    while (1)
    {
        int N, M, cnt=0;
        string row[23], col[23];
        cin >> N >> M;
        if (N == 0 && M == 0)break;
        int len = min(N, M), c = 0, r = 0;
        for (int i = 0; i < 2 * N + 1; i++) { if (i % 2 == 0)cin >> row[r++]; else cin >> col[c++]; }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < len; k++)
                {
                    bool check = true;
                    if (i + k >= N || j + k >= M)break;
                    for (int idx = j; idx <= j + k; idx++)if (row[i][idx] == '*') { check = false; break; }
                    for (int idx = j; idx <= j + k; idx++)if (row[i + k + 1][idx] == '*') { check = false; break; }
                    if (!check)continue;
                    for (int idx = i; idx <= i + k; idx++)if (col[idx][j] == '*') { check = false; break; }
                    for (int idx = i; idx <= i + k; idx++)if (col[idx][j + k + 1] == '*') { check = false; break; }
                    if (!check)continue;
                    cnt++;
                }
            }
        }
        cout << cnt << " squares" << "\n";
    }
}