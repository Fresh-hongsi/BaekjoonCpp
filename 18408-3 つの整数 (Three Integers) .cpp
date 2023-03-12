#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int arr[2]={0,};

	for (int i = 0; i < 3; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 1)
		{
			arr[0]++;
		}

		else
		{
			arr[1]++;
		}

	}

	if (arr[0] > arr[1])
	{
		cout << 1;
	}

	else
	{
		cout << 2;
	}

	return 0;
}
