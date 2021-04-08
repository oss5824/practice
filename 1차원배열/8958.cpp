#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n = 0; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char str[81];
		cin >> str;
		int len = strlen(str), start = 1, result = 0;
		for (int j = 0; j < len; j++)
		{
			if (str[j] == 'O')result += start++;
			else if (str[j] == 'X')start = 1;
		}
		printf("%d\n", result);
	}
	return 0;
}