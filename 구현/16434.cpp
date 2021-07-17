#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
int N; ll start_power, a, b, c, s, e, res = LLONG_MAX;
vector<pair<ll, ll>>v;//first가음수일 때 몬스터 공격력,생명력    , first가 양수일 때 용사의 공격력, 생명력
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> start_power;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c; 
        if (a == 1) {
            v.push_back({ -b,c });
            e = e + ((c / start_power) + 1) * b;
        }
        else v.push_back({ b,c });
    }
    while (s <= e) {
        ll m = (s + e) / 2;
        ll hp = m;
        ll power = start_power;
        bool check = true;
        for (int i = 0; i < N; i++) {
            ll cnt = 0;
            if (v[i].first < 0) {
                if (v[i].second <= power)cnt = 1;
                else if ((v[i].second % power) == 0) { cnt = v[i].second / power; }
                else cnt = (v[i].second / power) + 1;
                hp = hp + (cnt - 1) * v[i].first;
                if (hp <= 0) { check = false; break; }
            }
            else { power += v[i].first; hp += v[i].second; if (hp >= m)hp = m; }
        }
        if (check) { res = min(res, m); e = m - 1; }
        else s = m + 1;
    }
    cout << res;
}