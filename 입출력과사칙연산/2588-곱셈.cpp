#include<iostream>
using namespace std;
int main()
{
	int a, b; cin >> a >> b;
	cout << a * ((b % 100) % 10) << "\n" << a * ((b % 100 - ((b % 100) % 10))/10) << "\n" << a * (b / 100) << "\n" << a * b;
	return 0;
}