//math
//permutation

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool my_next_permutation(vector<int>& arr)
{
	int lastIdx = arr.size() - 1; //매개변수 순열의 마지막 인덱스
	int i = lastIdx; //i를 마지막 인덱스로 초기화

	while (i > 0 && arr[i - 1] >= arr[i]) //뒤에서부터 조사해 가장 내림차순이 긴 형태의 순열을 뽑아 그 순열의 첫번째 인덱스를 i로 지정
	{
		i--;
	}

	if (i <= 0) //만약 그 i가 0보다 작거나 같다면, 입력받은 순열 처음부터 끝까지 내림차순이라는 것이므로 다음 순열이 없음을 알림
	{
		return false;
	}

	int j = lastIdx; //i를 마지막 인덱스로 초기화
	while (arr[i - 1] >= arr[j]) //arr[i-1]<arr[j]를 만족하는 가장 큰 j를 찾음
	{
		j--;
	}

	swap(arr[i - 1], arr[j]); //arr[i-1]과 arr[j]를 swap

	for (int k = i; k <= (i + lastIdx) / 2; k++) //arr[i]부터 마지막 인덱스까지의 수를 서로 swap -> 내림차순을 오름차순으로 바꿔줌
	{
		swap(arr[k], arr[lastIdx]);
		lastIdx--;
	}

	return true; //다음 순열이 존재함을 알림

}



int main(void)
{
	int size = 0;
	cin >> size;

	vector<int> arr; //순열 담을 벡터
	while (size--)
	{
		int data = 0;
		cin >> data;
		arr.push_back(data);
	}

	if (my_next_permutation(arr)) //다음 순열이 존재한다면 순열을 출력
	{
		for (auto i : arr)
		{
			cout << i << ' ';
		}
	}

	else //다음순열이 존재하지 않다면 -1 출력
	{
		cout << -1;
	}

	return 0;
}
