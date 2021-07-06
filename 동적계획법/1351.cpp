#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll N, P, Q;
map<ll, ll>m;
ll sum;
ll cal(ll n)
{
    if (m.count(n))return m[n];
    return m[n] = cal(n / P) + cal(n / Q);
}
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> P >> Q; m[0] = 1;
    cout << cal(N);
}