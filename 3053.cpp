#pragma warning(disable:4996)
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int rad = 0;
	cin >> rad;
	printf("%f\n", M_PI * pow(rad, 2));
	printf("%f\n", 2 * pow(rad, 2));
	return 0;
}


