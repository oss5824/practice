#include <iostream>
using namespace std;
int N, la, ra, bb, ll, rl;
char Map[1002][1002];
pair<int, int>getHeart(){
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)if (Map[i][j] == '*')return { j,i + 1 };
}
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; for (int i = 0; i < N; i++)cin >> Map[i];
    pair<int, int>heart = getHeart();
    int y = heart.second, x = heart.first, mx = 0, my = 0;
    cout << y + 1 << " " << x + 1 << "\n";
    mx = x - 1; my = y; while (Map[my][mx] == '*' && mx >= 0) { mx--; la++; }
    mx = x + 1; my = y; while (Map[my][mx] == '*' && mx < N) { mx++; ra++; }
    mx = x; my = y + 1; while (Map[my][mx] == '*') { my++; bb++; }
    mx = x - 1; my = y + 1 + bb; while (Map[my][mx] == '*' && my < N) { my++; ll++; }
    mx = x + 1; my = y + 1 + bb; while (Map[my][mx] == '*' && my < N) { my++; rl++; }
    cout << la << " " << ra << " " << bb << " " << ll << " " << rl;
}