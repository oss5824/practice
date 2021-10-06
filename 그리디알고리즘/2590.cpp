#pragma warning(disable: 4996)
#include<stdio.h>
int arr[7];
int main()
{
	for (int i = 1; i <= 6; i++)scanf("%d", arr + i);
	int paper = 0;
	paper += arr[6];
	paper += arr[5]; arr[1] -= arr[5] * 11;
	paper += arr[4];
	while (arr[4] > 0)
	{
		arr[4]--;
		if (arr[2] >= 5)arr[2] -= 5;
		else if (arr[2] == 4) { arr[2] = 0; arr[1] -= 4; }
		else if (arr[2] == 3) { arr[2] = 0; arr[1] -= 8; }
		else if (arr[2] == 2) { arr[2] = 0; arr[1] -= 12; }
		else if (arr[2] == 1) { arr[2] = 0; arr[1] -= 16; }
		else arr[1] -= 20;
	}
	while (arr[3] > 0)
	{
		paper++;
		if (arr[3] >= 4) { arr[3] -= 4; }
		else if (arr[3] == 3) {
			arr[3] = 0;
			if (arr[2] >= 1)arr[2]--, arr[1] -= 5;
			else arr[1] -= 9;
		}
		else if (arr[3] == 2) {
			arr[3] = 0;
			if (arr[2] >= 3)arr[2] -= 3, arr[1] -= 6;
			else if (arr[2] == 2)arr[2] -= 2, arr[1] -= 10;
			else if (arr[2] == 1)arr[2] -= 1, arr[1] -= 14;
			else arr[1] -= 18;
		}
		else if (arr[3] == 1) {
			arr[3] = 0;
			if (arr[2] >= 5)arr[2] -= 5, arr[1] -= 7;
			else if (arr[2] == 4)arr[2] -= 4, arr[1] -= 11;
			else if (arr[2] == 3) arr[2] -= 3, arr[1] -= 15;
			else if (arr[2] == 2) arr[2] -= 2, arr[1] -= 19;
			else if (arr[2] == 1) arr[2] -= 1, arr[1] -= 23;
			else  arr[1] -= 27;
		}
	}
	while (arr[2] > 0) {
		paper++;
		if (arr[2] >= 9) { arr[2] -= 9; }
		else { arr[1] = arr[1] - (36 - 4 * arr[2]); arr[2] = 0; }
	}
	if (arr[1] > 0)
	{
		if (arr[1] % 36 == 0)paper += arr[1] / 36;
		else paper = paper + 1 + arr[1] / 36;
	}printf("%d",paper);
}
