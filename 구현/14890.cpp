#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, Map[100][100], result;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> Map[i][j];

    for (int i = 0; i < N; i++) {
        bool check = true;
        int beforeValue = Map[i][0], count = 1;
        bool bridge[100]; memset(bridge, false, sizeof(bridge));
        for (int j = 1; j < N; j++) {
            if (beforeValue == Map[i][j]) { count++; continue; }
            else {
                int curValue = Map[i][j];
                if (abs(curValue - beforeValue) > 1) { check = false; break; }
                if (beforeValue < curValue) {
                    if (count < M) { check = false; break; }
                    for (int k = 1; k <= M; k++) {
                        if (j - k >= 0 && beforeValue == Map[i][j - k] && !bridge[j - k]) {
                            bridge[j - k] = true;
                        }
                        else { check = false;  break; }
                    }
                    beforeValue = curValue; count = 1;
                }
                else {
                    for (int k = 0; k < M; k++) {
                        if (j < N && curValue == Map[i][j] && !bridge[j])bridge[j++] = true;
                        else { check = false; break; }
                    }
                    if (j == N)break;
                    beforeValue = Map[i][--j]; count = 1;
                }
            }
        }
        if (check)result++;
    }
    for (int i = 0; i < N; i++) {
        bool check = true;
        int beforeValue = Map[0][i], count = 1;
        bool bridge[100]; memset(bridge, false, sizeof(bridge));
        for (int j = 1; j < N; j++) {
            if (beforeValue == Map[j][i]) { count++; continue; }
            else {
                int curValue = Map[j][i];
                if (abs(curValue - beforeValue) > 1) { check = false;  break; }
                if (beforeValue < curValue) {
                    if (count < M) { check = false; break; }
                    for (int k = 1; k <= M; k++) {
                        if (j - k >= 0 && beforeValue == Map[j - k][i] && !bridge[j - k]) {
                            bridge[j - k] = true;
                        }
                        else { check = false; break; }
                    }
                    beforeValue = curValue; count = 1;
                }
                else {
                    for (int k = 0; k < M; k++) {
                        if (j < N && curValue == Map[j][i] && !bridge[j])bridge[j++] = true;
                        else { check = false; break; }
                    }
                    if (j == N)break;
                    beforeValue = Map[--j][i]; count = 1;
                }
            }
        }
        if (check)result++;
    }
    cout << result;
}