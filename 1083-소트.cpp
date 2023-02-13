#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N = 0; //배열의 길이
vector<int> arr; //배열
int change = 0; //바꾸기 횟수

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> change;



	int next = 0; //next인덱스 번지에 이제 가능한 최대 크기의 수가 들어와야함
	int change_idx = 0; //반복문 돌면서 찾은 현재 가장 최대 정수의 index
	int change_max = 0; //반복문 돌면서 찾은 현재 가장 최대 정수의 값

	while (change != 0 && next != N) //바꾸기 횟수가 남아있지 않거나 next번지가 배열의 마지막까지 다 이미 조사가 끝났다면 종료
	{
		change_idx = next;
		change_max = arr[change_idx];

		for (int i = next; i < N; i++)
		{
			if (change_max < arr[i] && i - next <= change) //바꿀 수 있는 범위 한도 내에서만 찾기
			{
				change_idx = i;
				change_max = arr[change_idx];
			}
		}

		arr.erase(arr.begin() + change_idx); //바꿀 수 있는 최대의 수를 배열에서 제거
		arr.insert(arr.begin() + next, change_max); //next자리에 찾은 최대크기의 수 삽입
		change = change - (change_idx - next);
		next++;

	}
	


	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;

}
