#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int N;
int p, f, s, v, a, b, c, d, e;
vector<pair<pair<int, int>, pair<pair<int, int>, int>>>vec;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> p >> f >> s >> v;
    for (int i = 0; i < N; i++) { cin >> a >> b >> c >> d >> e; vec.push_back({ {a,b},{{c,d},e} }); }
    int result = 1e9; string res = "99999999999999999999999999999999999999999999";
    for (int i = 1; i < (1 << N); i++) {
        int sump = 0, sumf = 0, sums = 0, sumv = 0, sum = 0;
        int tmp = i, pos = 0;
        string str;
        while (tmp) {
            if (tmp & 1) {
                sump += vec[pos].first.first;
                sumf += vec[pos].first.second;
                sums += vec[pos].second.first.first;
                sumv += vec[pos].second.first.second;
                sum += vec[pos].second.second;
                str = str + to_string(pos + 1) + " ";
            }
            tmp = tmp >> 1; pos++;
        }
        if (sump >= p && sumf >= f && sums >= s && sumv >= v) {
            if (sum < result) { result = sum; res = str; }
            else if (sum == result)if (res > str)res = str;
        }
    }
    if (result == 1e9)cout << "-1";
    else cout << result << "\n" << res;
}