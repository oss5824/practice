#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr1[4000], arr2[4000], arr3[4000], arr4[4000], n;
long long res;
vector<int>v1, v2;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1.push_back(arr1[i] + arr2[j]); v2.push_back(arr3[i] + arr4[j]);
        }
    }
    int len = v1.size();
    sort(v1.begin(), v1.end());
    for (int i = 0; i < len; i++) {
        int value = -v2[i];
        res += (long long)(upper_bound(v1.begin(), v1.end(), value) - lower_bound(v1.begin(), v1.end(), value));
    }cout << res;
}