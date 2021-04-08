#include <iostream>
using namespace std;
unsigned long long recursive(int A,int B,int C)
{
	if (B == 1)return A;
	else if (B == 0)return 1;

	if (B % 2 == 0)
	{
		unsigned long long res = recursive(A, B / 2, C) % C;
		return (res * res) % C;
	}
	else
	{
		unsigned long long res = recursive(A, (B - 1) / 2, C) % C;
		return ((res * res) % C * A) % C;
	}
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	printf("%llu", (recursive(A, B, C)) % C);
	return 0;
}