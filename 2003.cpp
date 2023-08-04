#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int startIdx = 0; //시작 포인터 
	int endIdx = 0; //단말 포인터
	int N = 0; //수열 길이
	int M = 0; //구간의 합이 참일 조건
	int resultCount = 0; //조건에 만족하는 답 개수
	int currentSum = 0; //현재 두 포인터에 의해 계산된 구간 합

	cin >> N >> M;
	
	
	vector<int> numArr(10001, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> numArr[i];
		
	}

	currentSum += numArr[0]; //시작 값 세팅
	
	
	while (!(endIdx == N))
	{
		if (currentSum == M)
		{
			startIdx++;
			endIdx++;
			resultCount++;
			currentSum -= numArr[startIdx - 1];
			currentSum += numArr[endIdx];
		}

		else if (currentSum < M)
		{
			endIdx++;
			currentSum += numArr[endIdx];
		}
		else if(currentSum>M)
		{
			startIdx++;
			currentSum -= numArr[startIdx - 1];
		}
	}

	cout << resultCount;
	return 0;

}
