//math
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int start = 0; //덧셈 시작할 시작 인덱스
	int end = 0; //마지막으로 덧셈할 인덱스
	cin >> start>>end;

	start -= 1; //배열이므로 인덱스값 계산 위해 실제 입력받은 값에서 1 빼주기
	end -= 1; //배열이므로 인덱스값 계산 위해 실제 입력받은 값에서 1 빼주기

	vector<int> arr;
	int num = 1; //현재 배열에 추가할 값
	int counter = 0; //배열에 마지막으로 더할 숫자까지 담겨있으면 더 담을 필요가 없으므로 counter값이 end+1(앞에서 1 빼주었으므로)값과 같아지면 배열에 숫자 담기 종료
	bool flag = false; //반복문 탈출위해 정의한 flag변수
	
	while (1)
	{
		
		for (int i = 0; i < num; i++)
		{
			if (counter == end + 1) //마지막으로 더할 숫자까지 배열에 담겨있다면 배열에 숫자 담는 과정 종료
			{
				flag = true;
				break;
			}

			arr.push_back(num); //숫자 담기
			counter++; //숫자 담았으므로 counter값 1 증가시킴
		}
		if (flag == true) //다 담겼으면 while문 탈출
		{
			break;
		}
		num++; //배열에 담을 수 1증가시킴
	}

	int sum = 0;

	for (int i = start; i <= end; i++) //선택한 시작 인덱스부터 마지막인덱스까지의 수를 더해줌
	{
		sum += arr[i];
	}

	cout << sum;
	return 0;
}
