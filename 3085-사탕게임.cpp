//brute-force

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<char>>arr(50, vector<char>(50, 0));
int line = 0; //사탕 기계의 가로, 세로 길이
int maxim=1; //먹을 수 있는 최대 사탕 개수
int cur; //현재 먹을 수 있는 최대 사탕 개수

void check()
{
	

	for (int i = 0; i < line; i++)
	{
		cur = 1;

		//열 최대 값 찾기

		for (int j = 0; j < line-1; j++)
		{
			if (arr[i][j] == arr[i][j+1]) //옆에 사탕 값이 똑같다면 현재 먹을 수 있는 사탕 개수 추가
			{
				cur++;
			}

			else //옆에 사탕 색깔이 다르다면 현재 먹을 수 있는 사탕과 지금까지 구해진 최대 사탕 값 비교 후 cur값을 1로 만들기
			{
				if (maxim < cur)
				{
					maxim = cur;
				}
				cur = 1;
			}
		}

		if (maxim < cur) //현재 먹을 수 있는 사탕과 지금까지 구해진 최대 사탕 값 한번 더 비교(else구문에 한번도 접촉되지 않는 경우 여기서 maxim값 구해짐)
		{
			maxim = cur;
		}

		
		//행 최대값 찾기
		cur = 1;

		
		for (int j = 0; j < line-1; j++)
		{
			if (arr[j][i] == arr[j+1][i]) //아래 사탕 값이 똑같다면 현재 먹을 수 있는 사탕 개수 추가
			{
				cur++;
			}
			else // 아래의 사탕 색깔이 다르다면 현재 먹을 수 있는 사탕과 지금까지 구해진 최대 사탕 값 비교 후 cur값을 1로 만들기
			{
				if (maxim < cur)
				{
					maxim = cur;
				}
				cur = 1;
			}
		}

		if (maxim < cur) // 현재 먹을 수 있는 사탕과 지금까지 구해진 최대 사탕 값 한번 더 비교(else구문에 한번도 접촉되지 않는 경우 여기서 maxim값 구해짐)
		{
			maxim = cur;
		}



	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//int line = 0;
	cin >> line;

	for (int i = 0; i < line; i++) //사탕 위치 초기화
	{
		string s;
		cin >> s;

		for (int j = 0; j < line; j++)
		{
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < line; i++) //모든 사탕에 대해서 오른쪽 스왑, 아래쪽 스왑해보고 그때의 최대 먹을 수 있는 사탕 개수 구하는 함수 호출 후, 다시 원위치로 돌려놓기
	{
		for (int j = 0; j < line; j++)
		{
			if (i < line-1) //아래랑 swap
			{
				swap(arr[i][j], arr[i + 1][j]);
				check();
				swap(arr[i][j], arr[i + 1][j]);
			}

			if (j < line - 1) //오른쪽과 swap
			{
				swap(arr[i][j], arr[i][j+1]);
				check();
				swap(arr[i][j], arr[i][j+1]);
			}
		}
	}

	cout << maxim<<'\n';
	return 0;
}
