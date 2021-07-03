#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
int N;
string s[5];
string input[5];
vector<int>v[10];
void check(int x, int front)
{
    for (int k = 0; k < 10; k++){
        bool fin = false;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 3; j++) {
                if (input[i][x + j] == '#' && s[i][4 * k + j] == '.') { fin = true; break; }
            }
            if (fin)break;
        }
        if (!fin)v[front].push_back(k);
    }
}
string str;
double sum = 0;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    s[0].append("###...#.###.###.#.#.###.###.###.###.###");
    s[1].append("#.#...#...#...#.#.#.#...#.....#.#.#.#.#");
    s[2].append("#.#...#.###.###.###.###.###...#.###.###");
    s[3].append("#.#...#.#.....#...#...#.#.#...#.#.#...#");
    s[4].append("###...#.###.###...#.###.###...#.###.###");
    for (int i = 0; i < 5; i++)cin >> input[i];
    for (int i = 0; i < N; i++)check(4 * i, i);
    for (int i = 0; i < N; i++)if (v[i].size() == 0) { printf("-1"); return 0;}
    for (int i = 0; i < N; i++)
    {
        double tmp = 0;
        for (int j = 0; j < v[i].size(); j++) { tmp += v[i][j];}
        sum += tmp * pow(10, N - 1 - i) / v[i].size();
    }
    printf("%.6f", sum);
}