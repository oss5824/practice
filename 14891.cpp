#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, sum;
void rotate_left(char* ch) { char c = ch[0]; for (int i = 0; i < 7; i++) ch[i] = ch[i + 1]; ch[7] = c; }
void rotate_right(char* ch) { char c = ch[7]; for (int i = 6; i >= 0; i--) ch[i + 1] = ch[i]; ch[0] = c; }
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	char first[9], second[9], third[9], fourth[9];
	cin >> first >> second >> third >> fourth;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			bool check1 = (first[2] == second[6]), check2 = (second[2] == third[6]), check3 = (third[2] == fourth[6]);
			(b == 1) ? rotate_right(first) : rotate_left(first);
			if (!check1) {
				(b == 1) ? rotate_left(second) : rotate_right(second);
				if (!check2){
					(b == 1) ? rotate_right(third) : rotate_left(third);
					if (!check3)(b == 1) ? rotate_left(fourth) : rotate_right(fourth);
				}
			}
		}
		else if (a == 2) {
			bool check1 = (first[2] == second[6]), check2 = (second[2] == third[6]), check3 = (third[2] == fourth[6]);
			(b == 1) ? rotate_right(second) : rotate_left(second);
			if (!check1) { (b == 1) ? rotate_left(first) : rotate_right(first); }
			if (!check2) {
				(b == 1) ? rotate_left(third) : rotate_right(third);
				if (!check3)(b == 1) ? rotate_right(fourth) : rotate_left(fourth);
			}
		}
		else if (a == 3) {
			bool check1 = (first[2] == second[6]), check2 = (second[2] == third[6]), check3 = (third[2] == fourth[6]);
			(b == 1) ? rotate_right(third) : rotate_left(third);
			if (!check2) {
				(b == 1) ? rotate_left(second) : rotate_right(second);
				if (!check1) {(b == 1) ? rotate_right(first) : rotate_left(first);}
			}
			if (!check3)(b == 1) ? rotate_left(fourth) : rotate_right(fourth);
		}
		else if (a == 4) {
			bool check1 = (first[2] == second[6]), check2 = (second[2] == third[6]), check3 = (third[2] == fourth[6]);
			(b == 1) ? rotate_right(fourth) : rotate_left(fourth);
			if (!check3) {
				(b == 1) ? rotate_left(third) : rotate_right(third);
				if (!check2) {
					(b == 1) ? rotate_right(second) : rotate_left(second);
					if (!check1)(b == 1) ? rotate_left(first) : rotate_right(first);
				}
			}
		}
	}
	if (first[0] == '1')sum += 1; if (second[0] == '1')sum += 2; if (third[0] == '1')sum += 4; if (fourth[0] == '1')sum += 8;
	cout << sum;
	return 0;
}

