//Data Structure
//Deque

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; //1부터 N까지의 숫자가 덱에 담김
	int M = 0; //뽑을 숫자 개수
	deque<int> dq;

	cin >> N >> M;
	
	queue<int> check; //덱에서 뽑을 숫자들이 저장된 큐

	for (int i = 0; i < M; i++) //입력받은 대로 큐에 순차적으로 뽑을 숫자를 저장
	{
		int temp;
		cin >> temp;
		check.push(temp);
	}


	for (int i = 1; i <= N; i++) //덱에 초기 양방향 순환 큐 세팅
	{
		dq.push_back(i);
	}

	

	int lShift = 0; //왼쪽 shift한 횟수
	int rShift = 0; //오른쪽 shift한 횟수
	bool flag = true;

	while (check.size()!=0) //큐가 비어있으면 우리가 알고자 하는 값을 다 구한 것이므로 이게 반복문 탈출조건임
	{
		int checker = check.front(); //해당 원소를 뽑기 위한 좌shift와 우shift 연산 수를 알아낼 것임
		check.pop(); //큐에서 하나씩 제거할 것

		int count = 0; //checker에 해당하는 수가 덱의 몇번째 인덱스에 있는 지 알아내기 위한 변수

		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] != checker) //만약 덱의 원소와 checker값이 다르면 count값 1증가시킴
			{
				count++;
			}

			if (dq[i] == checker) //같다면 checker변수와 같은 값이 해당 덱의 몇번째 인덱스인지 알아낸 것이므로 for문 탈출
			{
				
				break;
			}
		}

		if (count <= (dq.size()/2)) //count값이 덱의 크기/2보다 작거나 같다면 -> lShift해줘야함
		{
			//left shift해주는 과정
			for (int i = 0; i < count; i++)
			{
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				lShift++;
				
			}
		}

		else //count값이 덱의 크기/2보다 크다면 -> rShift해줘야함
		{

			//right shift해주는 과정
			for (int i = 0; i<dq.size()-count; i++)
			{
				int temp = dq.back();
				
				dq.pop_back();
				dq.push_front(temp);
				rShift++;
				
			}
		}

		//shift 과정 끝났으면 pop front해줌
		dq.pop_front();
		
	}

	//최소 연산 수: left+right shift횟수의 최소값
	cout << lShift + rShift;
	return 0;
}
