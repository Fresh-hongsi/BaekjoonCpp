#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;;

int R = 0;
int C = 0;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;
	vector<int>arr[40];

	for (int i = 0; i < R; i++) //이차원 배열 입력받음
	{
		for (int j = 0; j < C; j++)
		{
			int temp = 0;
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	vector<int> result; //필터링 통해 중앙값을 담을 배열


	//9칸짜리 필터링을 전수 적용후, 중앙값을 찾아 result배열에 저장하는 과정
	for (int i = 0; i < R - 2; i++)
	{
		for (int j = 0; j < C - 2; j++)
		{
			vector<int> pix; //필터링을 적용할 arr의 요소 9개를 임시 저장할 배열
			for (int k = i; k < i + 3; k++)
			{
				for (int l = j; l < j + 3; l++)
				{
					pix.push_back(arr[k][l]);
				}
			}
			sort(pix.begin(), pix.end()); //pix에 담긴 9개의 요소를 오름차순 정렬
			result.push_back(pix[4]); //중앙값을 result배열에 저장
		}
	}
	int T = 0;
	cin >> T;
	int answer = 0;
	for (auto& i : result) //result 배열 순회하며 T보다 크거나 같은 값이 발견되면 answer값 증가시킴
	{
		if (i >= T)
		{
			answer++;
		}
	}
	cout << answer;
	return 0;



}
