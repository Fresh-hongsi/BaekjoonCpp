//brute-force

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char arr[50][50];

	int N = 0;
	int M = 0;

	//현재 체스판 입력받기
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	//체스판 가공
	int count = 0; //변경해야할 칸의 개수
	bool flag = true;


	char checker1[8][8];
	char checker2[8][8];

	for (int i = 0; i < 8; i++) //w로 시작하는 기본 체스판
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j += 2)
			{
				checker1[i][j] = 'W';
			}

			for (int k = 1; k < 8; k += 2)
			{
				checker1[i][k] = 'B';
			}
		}

		else
		{
			for (int j = 0; j < 8; j += 2)
			{
				checker1[i][j] = 'B';
			}

			for (int k = 1; k < 8; k += 2)
			{
				checker1[i][k] = 'W';
			}
		}

	}



	for (int i = 0; i < 8; i++) //b로 시작하는 기본 체스판
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j += 2)
			{
				checker2[i][j] = 'B';
			}

			for (int k = 1; k < 8; k += 2)
			{
				checker2[i][k] = 'W';
			}
		}

		else
		{
			for (int j = 0; j < 8; j += 2)
			{
				checker2[i][j] = 'W';
			}

			for (int k = 1; k < 8; k += 2)
			{
				checker2[i][k] = 'B';
			}
		}

	}




	for (int i = 0; i <= N - 8; i++) //가능한 모든 경우에 대해 checker배열과 비교해서 가장 최소값이 되는 count값 찾기
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int comp1 = 0; //checker1에 적용했을 때 변경되는 값을 담는 변수
			int comp2 = 0; //checker1에 적용했을 때 변경되는 값을 담는 변수

			char temp[8][8]; //임시로 8*8배열을 가져와 담는 배열

			for (int l = 0; l < 8; l++) //가능한 경우에 대해 temp배열에 임시로 담아옴
			{
				for (int k = 0; k < 8; k++)
				{
					temp[l][k] = arr[i + l][j + k];
				}
			}

		


			comp1 = 0;
			comp2 = 0;



			for (int i = 0; i < 8; i++) //temp배열과 cheker1과 비교
			{
				for (int j = 0; j < 8; j++)
				{
					if (temp[i][j] != checker1[i][j])
					{
						comp1++;
					}

				}
			}



			for (int i = 0; i < 8; i++) //temp배열과 cheker2과 비교
			{
				for (int j = 0; j < 8; j++)
				{
					if (temp[i][j] != checker2[i][j])
					{
						comp2++;
					}


				}

			}


			if (flag == false) //두번째 이후 반복문 돌 때 count값이 checker1, checker2 적용했을 때보다 값이 크다면-> count값 변경 필요
			{
				if(count>min(comp1,comp2))
					count = min(comp1, comp2);
			}

			if (flag == true) //첫 반복문 돌 떄는 count값 무조건 담겨야함
			{
				count = min(comp1, comp2);
				flag = false;
			}

		}







	}
	//결과값 출력
	cout << count << endl;
}
