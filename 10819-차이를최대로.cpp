//Brute-Force
//Permutation

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int MaxValue(vector<int>& arr) //수식 최대값 계산해주는 함수
{
	int sum = 0;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		sum += abs(arr[i] - arr[i + 1]);
	}


	return sum;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	vector<int> arr;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end()); //next_permutation이 제대로 동작하려면 정렬이 되어있어야함
	int maxValue = 0; //수식의 최대값이 담길 변수
	
	do //next_permutation함수 호출되면 다음 순열이 구해지므로 do while구문 사용
	{
		int curMax = MaxValue(arr);
		if (maxValue < curMax) //만약 함수 호출해서 받은 값이 전에 있던 최대값보다 크다면 최대값 변경
		{
			maxValue = curMax;
		}
		
	} while (next_permutation(arr.begin(), arr.end()));
	

	cout << maxValue;
	
	return 0;

}
