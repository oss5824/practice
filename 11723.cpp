#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
bool arr[21];
using namespace std;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; cin.ignore(); memset(arr, false, sizeof(arr));
	for (int i = 0; i < n; i++)
	{
		char cmd[12]; int a;
		cin.getline(cmd, 12);
		char* token = strtok(cmd, " \n");
		if (!strcmp(token, "all")) { memset(arr, true, sizeof(arr));  }
		else if (!strcmp(token, "empty")) { memset(arr, false, sizeof(arr)); }
		else
		{
			a = atoi(strtok(NULL, "\n"));
			if (!strcmp(token, "check")) { if (arr[a] == true)cout << "1\n"; else cout << "0\n"; }
			else if (!strcmp(token, "add")) { if (arr[a] == false) arr[a] = true; }
			else if (!strcmp(token, "remove")) { if (arr[a] == true) arr[a] = false; }
			else if (!strcmp(token, "toggle")) { if (arr[a] == true)arr[a] = false; else arr[a] = true; }
		}
	}
	return 0;
}