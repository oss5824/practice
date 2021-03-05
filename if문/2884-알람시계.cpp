#include <iostream>
using namespace std;
int main()
{
	short h, m, a;
	cin >> h >> m;
	if (m < 45)
	{
		a = 45 - m;
		a = 60 - a;
		if (h == 0)printf("23 %d", a);
		else printf("%d %d", h - 1, a);
	}
	else printf("%d %d", h, m - 45);
	return 0;
}