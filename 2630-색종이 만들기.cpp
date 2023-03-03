#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int n = 0;
int blueCounter = 0;
int whiteCounter = 0;

int map[128][128] = { 0, };


void solve(int x, int y, int s)
{
	
	int curColor = map[x][y]; //현재 좌표의 색깔
	for (int i = x; i < x + s; i++)
	{
		for (int j = y; j < y + s; j++)
		{
			if (map[i][j] != curColor) //다른 색을 만나면 나눠서 분할정복
			{
				solve(x, y, s / 2); //좌상단
				solve(x, y + s / 2, s / 2); //우상단
				solve(x + s / 2, y, s / 2); //좌하단
				solve(x + s / 2, y + s / 2, s / 2); //우하단
				return; //아래재귀에서 모두 카운트 됐으므로 상위 (더 사이즈 큰 걸로 반환)
			}
		}

	}

	//이 부분은 해당 사이즈 제한 안에서 모든 색깔이 파란색일 때만 올 수 있음
	if (curColor == 1)
	{
		blueCounter++;
	}

	//이 부분은 해당 사이즈 제한 안에서 모든 색깔이 흰색일 때만 올 수 있음
	else
	{
		whiteCounter++;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = 0;
			cin >> temp;

			map[i][j] = temp;
		}
	}


	solve(0,0,n);

	cout << whiteCounter << '\n';
	cout << blueCounter;
	return 0;




}
