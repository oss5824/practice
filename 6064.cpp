#include <iostream>
using namespace std;
int main()
{
	int c = 0, r = 0;
	int h = 0, w = 0;
	cin >> c >> r;
	int** A = new int* [c];
	for (int i = 0; i < c; i++)A[i] = new int[r];
	for (int i = 0; i < c; i++)for (int j = 0; j < r; j++)cin >> A[i][j];

	cin >> h >> w;
	int** B = new int* [h];
	for (int i = 0; i < h; i++)B[i] = new int[w];
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)cin >> B[i][j];

	int** C = new int* [c];
	for (int i = 0; i < c; i++)C[i] = new int[w];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < w; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < r; k++)C[i][j] += A[i][k] * B[k][j];
		}
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < w; j++)printf("%d ", C[i][j]);
		printf("\n");
	}
	return 0;
}