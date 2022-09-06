#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;

	int roomSize = 0;
	int personPerSize = 0;

	cin >> roomSize >> personPerSize;

	for (int i = 0; i < 5; i++)
	{
		int person = 0;
		cin >> person;
		arr.push_back(person);
	}

	int exactPersonNum = roomSize * personPerSize;

	for (int i = 0; i < 5; i++)
	{
		arr[i] =  arr[i] - exactPersonNum;

		cout << arr[i] << ' ';
	}

	return 0;

	
}
