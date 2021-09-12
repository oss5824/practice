#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int n, h, res = 0, resCnt = 1e9; vector<int>bot, top;
    cin >> n >> h;
    for (int i = 0, a, b; i < n / 2; i++) { cin >> a >> b; bot.push_back(a), top.push_back(b); }
    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());
    for (int i = 1; i <= h; i++) {
        int cnt = n - ((lower_bound(bot.begin(), bot.end(), i) - bot.begin())
            + upper_bound(top.begin(), top.end(), h - i) - top.begin());
        if (cnt < resCnt)res = 1, resCnt = cnt;
        else if (resCnt == cnt)res++;
    }
    cout << resCnt << " " << res;
}