#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long arr1[1000], arr2[1000], target, n, m, val;
vector<long long>v1, v2;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> target;
    cin >> n; for (int i = 0; i < n; i++)cin >> arr1[i];
    cin >> m; for (int i = 0; i < m; i++)cin >> arr2[i];
    for (int i = 0; i < n; i++) {
        long long sum = 0; for (int j = i; j < n; j++) { sum += (long long)arr1[j]; v1.push_back(sum); }
    }
    for (int i = 0; i < m; i++) {
        long long sum = 0; for (int j = i; j < m; j++) { sum += (long long)arr2[j]; v2.push_back(sum); }
    }
    sort(v1.begin(), v1.end());
    long long sz = v2.size();
    for (int i = 0; i < sz; i++) {
        long long remain = target - v2[i];
        val += upper_bound(v1.begin(), v1.end(), remain) - lower_bound(v1.begin(), v1.end(), remain);
    }
    cout << val;
}