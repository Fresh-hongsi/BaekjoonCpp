//greedy
//sorting

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> input; //돈을 인출하는 데 필요한 시간을 입력받을 배열

	int n = 0; //사람 수
	cin >> n;

	while (n--) //인출하는 데에 걸리는 시간 입력받기
	{
		int temp = 0;
		cin >> temp;
		input.push_back(temp);
	}

	//최소 시간을 구하기 위해서는 시간이 적게 걸리는 순서대로 인출해야 최적임
	sort(input.begin(), input.end());

	int sum = 0; //현재 인출하는 사람이 돈을 인출하는 데에 필요한 시간
	int result = 0; //각 사람이 인출하는 데에 필요한 시간의 합
	for (int i = 0; i < input.size(); i++)
	{
		int temp = input[i]; //현재 사람이 인출하는데 걸리는 시간
		sum += temp; //앞선 사람들까지의 시간의 합에 temp값 더한 값이 현재 인출하는 사람이 돈을 인출하는 데에 필요한 시간임
		result += sum; //결과값에 sum값 추가해가며 더하기
	}

	cout << result << '\n';
	return 0;
}
