#include <iostream>
#include <string>
using namespace std;
int N, M;
string Map[20], result = "zzzzzzzzzzzzzzzzzzzz";
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)cin >> Map[i];
    for (int i = 0; i < N; i++)
    {
        int pos = 0; string tmp = "";
        while (pos < M)
        {
            if (Map[i][pos] == '#') {
                if (!tmp.empty()) {
                    if (tmp.length() >= 2 && result > tmp)result = tmp; tmp = "";
                }pos++;
            }
            else tmp += Map[i][pos++];
        }
        if (!tmp.empty()) { if (tmp.length() >= 2 && result > tmp)result = tmp; }
    }
    for (int i = 0; i < M; i++)
    {
        int pos = 0; string tmp = "";
        while (pos < N)
        {
            if (Map[pos][i] == '#') {
                if (!tmp.empty()) {
                    if (tmp.length() >= 2 && result > tmp)result = tmp; tmp = "";
                }pos++;
            }
            else tmp += Map[pos++][i];
        }
        if (!tmp.empty()) { if (tmp.length() >= 2 && result > tmp)result = tmp; }
    }
    cout << result;
}