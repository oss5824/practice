#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n = 0;
	char c = '%';
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int count = 0, num = 0;
		cin >> count;
		float* arr = new float[count];
		float result = 0, res = 0;
		for (int j = 0; j < count; j++)cin >> arr[j];
		for (int j = 0; j < count; j++)result += arr[j];
		result = result / (float)count;
		for (int j = 0; j < count; j++)if (result < arr[j])num++;
		res = ((float)num / (float)count) * 100;
		printf("%.3f%c\n", (round((res) * 1000)) / 1000.0, c);
	}
	return 0;
}