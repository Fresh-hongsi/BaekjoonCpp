//분할정복
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;

int N = 0;
int map[2188][2188] = { 0, };

int minus1Num = 0;
int zeroNum = 0;
int plus1Num = 0;
void solve(int x, int y, int depth)
{
	int curColor = map[x][y];

	for (int i = x; i < x + depth; i++)
	{
		for (int j = y; j < y + depth; j++)
		{
			if (map[i][j] != curColor)
			{
				solve(x, y, depth / 3);
				solve(x, y + (depth / 3), depth / 3);
				solve(x, y + ((2 * depth) / 3), depth / 3);
				solve(x + (depth / 3), y, depth / 3);
				solve(x + (depth / 3), y + (depth / 3), depth / 3);
				solve(x + (depth / 3), y + ((2 * depth) / 3), depth / 3);
				solve(x + ((2 * depth) / 3), y, depth / 3);
				solve(x + ((2 * depth) / 3), y + (depth / 3), depth / 3);
				solve(x + ((2 * depth) / 3), y + ((2 * depth) / 3), depth / 3);
				return;

			}
		}
	}

	if (curColor == -1)
	{
		minus1Num++;
	}

	else if (curColor == 0)
	{
		zeroNum++;
	}

	else if (curColor == 1)
	{
		plus1Num++;
	}
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			map[i][j] = temp;
		}
	}


	solve(0, 0, N);

	cout << minus1Num << '\n';
	cout << zeroNum << '\n';
	cout << plus1Num;
	return 0;

}
