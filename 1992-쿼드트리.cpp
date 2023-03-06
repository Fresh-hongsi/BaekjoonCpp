//분할정복
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int N = 0;
int map[64][64] = { 0, };


void solve(int x, int y,int depth)
{
	
	//현재 보고있는 지점의 색깔확인(흑 or 백)
	int curColor = map[x][y];

	//depth가 1일때가 마지막임 
	for (int i = x; i < x+depth; i++)
	{
		for (int j = y; j < y+depth; j++)
		{
			if (map[i][j] != curColor) //색깔이 다르면 분할정복 한번더
			{
				cout << "(";
				solve(x, y, depth / 2); //2사분면
				solve(x, y + depth / 2, depth / 2); //1사분면
				solve(x + depth / 2, y, depth / 2); //3사분면
				solve(x + depth / 2, y + depth / 2, depth / 2); //4사분면
				cout << ")"; 
				return;
			}
		}
	}

	cout << curColor;

	
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;

	//흑백영상 입력
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;
		for (int j = 0; j < t.length(); j++)
		{
			
			map[i][j] = t[j]-48;
		}
	}

	//분할정복 시작
	solve(0, 0, N);
	return 0;

}
