#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int width = 0, heigth = 0, min = -1;
	cin >> heigth >> width;
	char** arr = new char* [heigth];
	char wb[9][9], bw[9][9];
	for (int i = 0; i < heigth; i++)arr[i] = new char[width + 1];
	for (int i = 0; i < 8; i++)
	{
		char color = (i % 2 == 0) ? 'W' : 'B';
		char color2 = (i % 2 == 0) ? 'B' : 'W';
		for (int j = 0; j < 8; j++)
		{
			wb[i][j] = color;
			bw[i][j] = color2;
			color = (color == 'B') ? 'W' : 'B';
			color2 = (color2 == 'B') ? 'W' : 'B';
		}
	}

	for (int i = 0; i < heigth; i++)
		cin >> arr[i];
	for (int i = 0; i < heigth - 7; i++)
	{
		for (int j = 0; j < width - 7; j++)
		{
			int count_wb = 0, count_bw = 0, local_min = 0;
			for (int h = 0; h < 8; h++)
			{
				for (int w = 0; w < 8; w++)
				{
					count_wb = (arr[i + h][j + w] != wb[h][w]) ? count_wb + 1 : count_wb;
					count_bw = (arr[i + h][j + w] != bw[h][w]) ? count_bw + 1 : count_bw;
				}
			}
			local_min = (count_wb > count_bw) ? count_bw : count_wb;
			min = ((min > local_min) || min == -1) ? local_min : min;
		}
	}
	cout << min << endl;
}
