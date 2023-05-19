#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr;
	bool flag = true;
	for (int i = 0; i < 8; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	for (auto i : arr)
	{
		if (i != 0 && i != 1)
		{
			flag = false;
			break;
		}
	}

	if (flag == true)
	{
		cout << 'S';
	}

	else
	{
		cout << 'F';
	}

}
