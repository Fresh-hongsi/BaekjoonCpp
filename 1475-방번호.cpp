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

	string roomNum; //방번호 입력
	cin >> roomNum;

	vector<int> arr; //각 숫자의 개수가 담긴 배열 -> 6이랑 9는 특수한 경우이므로 이 배열가지고 특수한 연산 수행할 것

	for (int i = 0; i < 10; i++) //일단 배열의 값을 모두 0으로 세팅
	{
		arr.push_back(0);
	}

	

	for (int i = 0; i < roomNum.size(); i++) //방 번호에서 각 숫자가 몇개 들어있는지 알아냄
	{
		arr[roomNum[i]-48]++;

	}

	arr[6] += arr[9]; //6은 9를 뒤집어서 쓸 수 있으므로 6과 9를 하나로 통일해서 생각-> 나는 9값을 6으로 합칠 것
	arr[9] = 0; //6에 9의 개수를 추가했으므로 9값은 0으로 다시 세팅

	if (arr[6] % 2 == 0) //만약 6이 짝수개라면 세트는 6의 개수/2개 필요
	{
		arr[6] /= 2;
	}

	else //6이 홀수개 있다면 6의 개수/2+1개의 세트 필요
	{
		arr[6]= arr[6]/ 2+1;
	}
	
	sort(arr.begin(), arr.end()); //arr의 배열에서 가장 큰 값이 곧 필요한 세트의 수임
	int result = arr[9]; //최대값 찾기

	cout << result;
	return 0;


}
