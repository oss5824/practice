#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
map<int, string>m;
int arr[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
int solve(string s)
{
	int sum = 0, i = 0, len = s.length();
	while (i < len){
		if (i != len - 1 && (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')){
			if (s[i] == 'I') {
				if (s[i + 1] == 'V') { sum += 4; i = i + 2; continue; }
				else if (s[i + 1] == 'X') { sum += 9; i = i + 2; continue; }
			}
			else if (s[i] == 'X') {
				if (s[i + 1] == 'L') { sum += 40; i = i + 2; continue; }
				else if (s[i + 1] == 'C') { sum += 90; i = i + 2; continue; }
			}
			else if (s[i] == 'C') {
				if (s[i + 1] == 'D') { sum += 400; i = i + 2; continue; }
				else if (s[i + 1] == 'M') { sum += 900; i = i + 2; continue; }
			}
		}
		if (s[i] == 'I')sum += 1;
		else if (s[i] == 'V')sum += 5;
		else if (s[i] == 'X')sum += 10;
		else if (s[i] == 'L')sum += 50;
		else if (s[i] == 'C')sum += 100;
		else if (s[i] == 'D')sum += 500;
		else if (s[i] == 'M')sum += 1000;
		i++;
	}
	return sum;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	int sum1 = solve(s1), sum2 = solve(s2);
	m[1000] = "M"; m[500] = "D"; m[100] = "C"; m[50] = "L"; m[10] = "X"; m[5] = "V";
	m[1] = "I"; m[4] = "IV"; m[9] = "IX"; m[40] = "XL"; m[90] = "XC"; m[400] = "CD";
	m[900] = "CM";
	int sum = sum1 + sum2, idx = 0;
	cout << sum << "\n";
	while (sum != 0) {
		int cnt = 0;
		if ((cnt = (sum / arr[idx])) >= 0)sum = sum - (arr[idx] * (sum / arr[idx]));
		while (cnt--)cout << m[arr[idx]];
		idx++;
	}
	return 0;
}

