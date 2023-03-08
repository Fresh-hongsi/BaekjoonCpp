//분할정복
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N = 0; //배열의 크기 관련 변수
int R = 0; //타깃의 행 좌표
int C = 0; //타깃의 열 좌표
int counter = 0; //타깃에 도달할 때까지 타깃value를 +1해주기 위한 변수
int result = 0; //타깃에 해당하는 result값

void solve(int x, int y, int depth)
{
	
	if (depth == 2) //탈출조건 -> 구할 수 있는 범위
	{
		for (int i = x; i < x + depth; i++)
		{
			for (int j = y; j < y + depth; j++)
			{
				
				if (i == R && j == C) //타깃 위치에 도달했으면 result변수에 counter값 저장하고 반환
				{
					result = counter;
					return;
				}
				counter++; //아직 타깃 위치에 도달하지 않았다면 counter값 1 증가시킴
			}
		}
	}

	//분할하는 구간
	else
	{
		solve(x, y, depth / 2); //해당 권역에서의 1사분면 쪼개서 들어가기
		solve(x, y + (depth / 2), depth / 2); //해당 권역에서의 2사분면 쪼개서 들어가기
		solve(x + (depth / 2), y, depth / 2); //해당 권역에서의 3사분면 쪼개서 들어가기
		solve(x + (depth / 2), y + (depth / 2), depth / 2); //해당 권역에서의 4사분면 쪼개서 들어가기
		return; //분할 정복 완료됐으면 반환하기
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> N; 
	cin >> R >> C;

	if (N >= 2) //너무 큰 배열일 경우에 대비해 미리 타깃의 위치가 초기 배열의 4분면 중 몇사분면에 있는 지 확인 후 쪼개놓고 분할정복하기
	{
		if (R >= 0 && R < (pow(2, N) / 2) && C >= 0 && C < (pow(2, N) / 2)) //1사분면에 타깃이 있을 경우
		{
			counter = 0; //counter값 0으로 설정
			solve(0, 0, pow(2, N) / 2);
		}

		else if (R >= 0 && R < (pow(2, N) / 2) && C >= (pow(2, N) / 2) && C < pow(2, N)) //2사분면에 타깃이 있을 경우
		{
			counter = (pow(2, N) / 2) * (pow(2, N) / 2); //counter값을 맞는 값으로 설정
			solve(0, pow(2, N) / 2, pow(2, N) / 2);
		}

		else if (R >= (pow(2, N) / 2) && R < pow(2, N) && C >= 0 && C < (pow(2, N) / 2)) //3사분면에 타깃이 있을 경우
		{
			counter = (pow(2, N) / 2) * (pow(2, N) / 2) * 2; //counter값을 맞는 값으로 설정
			solve(pow(2, N) / 2, 0, pow(2, N) / 2);
		}

		else if (R >= (pow(2, N) / 2) && R < pow(2, N) && C >= (pow(2, N) / 2) && C < pow(2, N)) //4사분면에 타깃이 있을 경우
		{ 
			counter = (pow(2, N) / 2) * (pow(2, N) / 2) * 3; //counter값을 맞는 값으로 설정
			solve(pow(2, N) / 2, pow(2, N) / 2, pow(2, N) / 2);
		}
	}

	else //만일 N이 1이어서 굳이 4분면으로 미리 나눌 필요가 없는경우 그냥 바로 분할정복 시작
	{
		solve(0, 0, pow(2, N));
	}
	
	

	cout << result; //결과값 출력
	return 0;

}
